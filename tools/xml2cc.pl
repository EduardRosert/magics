#!/usr/bin/perl
# (C) Copyright 1996-2016 ECMWF.
# 
# This software is licensed under the terms of the Apache Licence Version 2.0
# which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
# In applying this licence, ECMWF does not waive the privileges and immunities 
# granted to it by virtue of its status as an intergovernmental organisation nor
# does it submit to any jurisdiction.


use XML::Parser;
use Time::localtime;

my $file  = shift;
my $dir   = shift;
my $nosubdir = shift;

my $Author="MagicsTeam";
my $ecmwf="http://wms.ecmwf.int";
my $info = {};
my $element = {};


my %basetype = (
    "int" => 1,
    "float" => 1,
    "string" => 1,
    "bool"=>1,
    "floatarray" =>1,
    "stringarray" => 1,
    "intarray" => 1, 
    "longintarray" => 1, 
    "LineStyle" =>1,
    "ListPolicy" =>1,
    "Hemisphere" =>1,
    "ArrowPosition" => 1,
    "AxisAutomaticSetting" => 1,
    "Justification" => 1,
    "Position" => 1,
    "DisplayType" => 1,
    "OpenGLDriverObserverPtr" => 1,
    "Widget" =>1, 
    "cairo_t*" =>1,
    "QWidget*" =>1,
    "QGraphicsScene*" => 1,
    "Matrix" => 1,
    "GribHandlePtr" =>1,  
);

my %translator = (
    "int" => "ParameterManager::getInt",
    "float" => "ParameterManager::getDouble",
    "string" => "ParameterManager::getString",
    "stringarray" => "ParameterManager::getStringArray",
    "bool" => "ParameterManager::getBool",
    "doublearray" => "ParameterManager::getDoubleArray",
    "floatarray" => "ParameterManager::getDoubleArray",
    "intarray" => "ParameterManager::getIntArray",
    "longintarray" => "ParameterManager::getLongIntArray"
    
);
my %magtype = (
	"float" =>'double',
);
my %consttype = (
	"string" =>'const string&',
);

my %classtype = (
	"Colour" =>1,
	"DateTime" =>1,
	"Path" => 1
);

my %arraytype = (
	"floatarray" => "atof(data)",
	"stringarray" => "data",
	"intarray" => "atoi(data)",
	"longintarray" => "atoi(data)",
);

my %quote = (
    "string" => 1,
);

sub parse
{
    my $def = shift;
    my $node = shift;   
   
    while ( defined ( $element = shift @{ $node } ) )
    {
       
        my $child = shift @{ $node };
        if ( ref $child )
        {
           my $attr = \%{ shift @{ $child } };
           my $name = $attr->{name};
           
           if ($name ne "") 
           {
               
               $def->{$element}->{$name} = {};
               my $list = $element . "_list";
               push( @{$def->{$list}}, $name);
               foreach my $a (keys %{$attr}) 
               {
                   $def->{$element}->{$name}->{attributes}->{$a} = $attr->{$a}; 
                  
               }
               parse($def->{$element}->{$name}, $child); 
               
           }
           else
           {
                   $def->{$element} = {};
                   foreach my $a (keys %{$attr}) 
                   {
                        $def->{$element}->{attributes}->{$a} = $attr->{$a};
                       
                   }
                   parse($def->{$element}, $child); 
           }
        }
        else 
        {
         
          $def->{data} = $child;
        }
    }   
}

my $xml= new XML::Parser(Style=>"Tree");
  
parse ($info, $xml->parsefile($file));

foreach my $object (keys %{$info->{magics}->{class}}) 
{
    $current = $info->{magics}->{class}->{$object};
    $directory = $info->{magics}->{class}->{$object}->{attributes}->{directory};
    $tag = $info->{magics}->{class}->{$object}->{attributes}->{xmltag};

    my $location;
    if( defined $nosubdir and $nosubdir eq "nosubdir" ) { 
        $location  = $dir; 
    }
    else { 
        $location  = "$dir/$directory"; 
    }
        
######################################################
#####                Include file

    open STDOUT, ">$location/$object\Attributes.h";

    my $string =  ctime();
    print  <<EOF;
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file $object\Attributes.h
    \\brief Definition of $object Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: $string
*/
   

#ifndef $object\Attributes_H
#define $object\Attributes_H

#include "magics.h"
EOF

    if (index($object, "Matrix") != -1) {
       print "#include \"Matrix.h\"\n";
    } 
    if (index($object, "Cairo") != -1) {
       print "#include \"cairo.h\"\n";
    } 

    my $includes = {};
    my @impl=split(/\//, $current->{attributes}->{implements});
    my @prefixs=split(/\//, $current->{attributes}->{prefix});
   
    my @interfaces = (split(/\//, $current->{attributes}->{interface}), @impl);
    
    foreach $i (@impl) 
    {
        print "#include \"$i.h\"\n";
    }
    
    my $parent ='';
    my $sep = ":";
    foreach $interface (@interfaces) 
    {
        $parent="$parent$sep public $interface";
        $sep = ", " 
    }

    foreach my $param (@{$current->{parameter_list}}) 
    {   
       my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
       next if $todo eq 'no';
       my $to = $current->{parameter}->{$param}->{attributes}->{to};
       my $include = $current->{parameter}->{$param}->{attributes}->{include};
       
       if ( !$basetype{$to} )
       {
            if ($include eq "" ) {
                $includes->{"$to.h"} = "ok";
            }
            else 
            {
                $includes->{$include} = "ok";
            }    
        }
     
    }
    foreach my $include (keys %{$includes} ) 
    {
          print "#include \"$include\"\n"; 
    }
    print "\n";
    
    my $template = $current->{attributes}->{template_attributes};
    my $class = "$object\Attributes";
    my $line = "";
    if ( $template ne "" ) {
        $line = "template <class $template>";
        $class = "$object\Attributes<$template>";
        
    }
    
    print <<EOF;
namespace magics {

class XmlNode;

$line
class $object\Attributes $parent
{
public:
//  --  constructor
    $object\Attributes();
    
//  --  destructor
    virtual ~$object\Attributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const $object\Attributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
EOF
     
    print "\tstring $xml_data\_;\n" unless $xml_data eq ''; 
    foreach  my $param (@{$current->{parameter_list}}) 
    {      
        my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        next if $todo eq 'no';
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
        $to = "$to<$tpl> " unless $tpl eq "";
        
        if ( $magtype{$to}  )
        { 
            print "\t$magtype{$to} $member\_;\n";
        }
        elsif ( $basetype{$to} ) 
        { 
            print "\t$to $member\_;\n";
        }
        else 
        {
            print "\tauto_ptr<$to> $member\_;\n";  
        }
    }

print <<EOF;   

private:
	friend ostream& operator<<(ostream& s,const $class& p)
	{ p.print(s); return s; }
};

} // namespace magics
EOF

    if ( $template ne "" ) {
        print "#include \"$object\Attributes.cc\" \n";
    }
    
    print "\n#endif\n";
 
    close STDOUT;
    
#####                Include file
######################################################

######################################################
#####                Source file

    open STDOUT, ">$location/$object\Attributes.cc";

    print  <<EOF;
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file $object\Attributes.cc
    \\brief Implementation of $object Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: $string
*/    

#include "$object\Attributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EOF
   $header = "";
    $p = "";
   if ( $template ne "" ) {
        $header = "template <class $template>";
        $p = "<P>";
    }
    
    my $count = 0;
    
    foreach  my $param (@{$current->{parameter_list}}) 
    {      
        my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
        next if $todo eq 'no';
        next if $tpl  ne "";
        $count++;
    }
    
    my $subclass = ":";
    $subclass = "" if $count eq 0; 
    
    print "$header\n$object\Attributes$p\::$object\Attributes()$subclass"; 
    my $sep = ""; 
    foreach  my $param (@{$current->{parameter_list}}) 
    {      
        my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        next if $todo eq 'no';
        
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $default = $current->{parameter}->{$param}->{attributes}->{default};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $from = $current->{parameter}->{$param}->{attributes}->{from};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
        my $constant= $current->{parameter}->{$param}->{attributes}->{constant};
        next if $tpl ne "";
        $to = "$to<$tpl> " unless $tpl eq "";
        my $magto = $to;
        $magto = $magtype{$to} if $magtype{$to};
        $from = $magtype{$from} if $magtype{$from};
      %xxx = {
    "int" => "ParameterManager::getInt",
    "float" => 1,
    "string" => ParameterManager::getString,
};
        if ($constant eq "yes" ) 
        {
            if ($translator{$to} ne '') {
                print "$sep\n\t$member\_($translator{$to}(\"$default\"))";
            }
            else {
        	    print "$sep\n\t$member\_(MagTranslator<$from, $magto>().magics(\"$default\"))"; 
            }
        } 
        else {
           
            if ($translator{$to} ne '') {
                print "$sep\n\t$member\_($translator{$to}(\"$name\"))";
            }
            else {
        	    print "$sep\n\t$member\_(MagTranslator<$from, $magto>().magics(\"$name\"))"; 
            }
        }
		$sep = ",";
    }
	print "\n";
    print <<EOF;
{
EOF
   foreach  my $param (@{$current->{parameter_list}}) 
    {   
    	my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        next if $todo eq 'no';
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
        next if $tpl eq "";
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $default = $current->{parameter}->{$param}->{attributes}->{default};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $from = $current->{parameter}->{$param}->{attributes}->{from};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $method = ucfirst $member;
        
        $to = "$to<$tpl> " unless $tpl eq "";
        my $magto = $to;
        $magto = $magtype{$to} if $magtype{$to};
        $from = $magtype{$from} if $magtype{$from};
	
        print "\tset$method(MagTranslator<string, $magto>()(\"$name\"));\n";
   }
   print <<EOF;
} 

$header
$object\Attributes$p\::~$object\Attributes()
{
}

$header    
EOF
	$val = 0;
	my $code = "";
	my $nb = $#prefixs+1;
	
	$code = "\tvector<string> prefix($nb);\n";
	$j = 0;
	for ($i = $nb; $i > 0; --$i) {		
		$code = "$code\tprefix[$j] = \"@prefixs[$i-1]\";\n";
		++$j;
	}
	$code = "$code\n";
	
	   
    foreach  my $param (@{$current->{parameter_list}}) 
    {
        my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        next if $todo eq 'no';
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $default = $current->{parameter}->{$param}->{attributes}->{default};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $from = $current->{parameter}->{$param}->{attributes}->{from};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
        my $xml = $current->{parameter}->{$param}->{attributes}->{xml};
        
        $to = "$to<$tpl> " unless $tpl eq "";
        my $magto = $to;
     
        my $method = ucfirst $member;
        $magto = $magtype{$to} if $magtype{$to};
        $from = $magtype{$from} if $magtype{$from};
        	
        	if ( $basetype{$to} ) 
            { 
            	$code = "$code\tsetAttribute(prefix, \"$name\", $member\_, params);\n";          		
            }
            elsif ( $to eq 'Colour')   {
            	$code = "$code\tsetAttribute(prefix, \"$name\", $member\_, params);\n" 
            }
            else {
            	$code = "$code\tsetMember(prefix, \"$name\", $member\_, params);\n"   
            }                     
    }
        
 if ($code eq "") {
 	print "void $object\Attributes$p\::set(const std::map<string, string>&)\n{\n}\n";
 }
 else {
 	print "void $object\Attributes$p\::set(const std::map<string, string>& params)\n{\n";
 	print "$code}\n"
 } 

print  <<EOF;
$header
void $object\Attributes$p\::copy(const $object\Attributes& other)
{
EOF

    foreach  my $param (@{$current->{parameter_list}}) 
    {
        my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        next if $todo eq 'no';
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $default = $current->{parameter}->{$param}->{attributes}->{default};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $from = $current->{parameter}->{$param}->{attributes}->{from};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
        my $xml = $current->{parameter}->{$param}->{attributes}->{xml};
         my $xml_data = $current->{attributes}->{xml_data};
        $to = "$to<$tpl> " unless $tpl eq "";
        my $magto = $to;
        my $method = ucfirst $member;
        $magto = $magtype{$to} if $magtype{$to};
        $from = $magtype{$from} if $magtype{$from};
        
        if ( $basetype{$to} ) 
        {         	
             print "\t$member\_ = other.$member\_;\n"; 
        }
        else 
        {
           print "\t$member\_ = auto_ptr<$to>(other.$member\_->clone());\n";          
        }
       
        print "";
       
        
    }
print  <<EOF;
} 

$header
bool $object\Attributes$p\::accept(const string& node)
{	
EOF
	print "\tif ( magCompare(node, \"$tag\")  )";
	print "\n\t\treturn true;\n";
	foreach  my $param (@{$current->{parameter_list}}) {
    			my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
    			next if $todo eq 'no';
    			my $to = $current->{parameter}->{$param}->{attributes}->{to};
    			next if $basetype{$to};
    			next if $classtype{$to};
    			my $member = $current->{parameter}->{$param}->{attributes}->{member};
    			my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
    			$to = "$to<$tpl> " unless $tpl eq "";
    			my $magto = $to;
        		my $method = ucfirst $member;
        		$magto = $magtype{$to} if $magtype{$to};
    			print "\n\tif ( acceptNode(node, $member\_) )\n";    
    			print "\t\treturn true;\n";    			
	}
	
print  <<EOF;
	return false;
}
$header
void $object\Attributes$p\::set(const XmlNode& node)
{
	if ( this->accept(node.name()) == false ) 
		return;
EOF
	if ( $tag ne '') {
		print "\n\tif ( magCompare(node.name(), \"$tag\") )";
		print "\n\t\tset(node.attributes());";
		print "\n\telse {";
		foreach  my $param (@{$current->{parameter_list}}) {
    			 my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
    			next if $todo eq 'no';
    			my $to = $current->{parameter}->{$param}->{attributes}->{to};
    			next if $basetype{$to};
    			next if $classtype{$to};
    			my $member = $current->{parameter}->{$param}->{attributes}->{member};
    			my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
    			$to = "$to<$tpl> " unless $tpl eq "";
    			my $magto = $to;
        		my $method = ucfirst $member;
        		$magto = $magtype{$to} if $magtype{$to};
    			
    			print "\n\t\tsetMember(node.name(), $member\_, node);";
    			
       
    	}
		print "\n\t}";
	}
	else {
		print "\n\tset(node.attributes());";
	}
	
	if ($xml_data ne '') {
		print "\n\tfor (XmlNode::DataIterator data = node.firstData(); data != node.lastData(); ++data)\n";
		print "\t\tsetXmlData(*data);\n";	
	}
	print "\n";
	print "\tfor (XmlNode::ElementIterator elt = node.firstElement(); elt != node.lastElement(); ++elt) {\n";
    		foreach  my $param (@{$current->{parameter_list}}) {
    			 my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
    			next if $todo eq 'no';
    			my $to = $current->{parameter}->{$param}->{attributes}->{to};
    			next if $basetype{$to};
    			next if $classtype{$to};
    			my $member = $current->{parameter}->{$param}->{attributes}->{member};
    			my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
    			$to = "$to<$tpl> " unless $tpl eq "";
    			my $magto = $to;
        		my $method = ucfirst $member;
        		$magto = $magtype{$to} if $magtype{$to};

    			print "\t\tsetMember((*elt)->name(), $member\_, *(*elt)); \n";
    	}

print <<EOF; 		
	}
}
$header
void $object\Attributes$p\::print(ostream& out)  const
{
	out << "$object\Attributes[";
EOF
    $sep = "";
    foreach  my $param (@{$current->{parameter_list}}) 
    {      
         my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
       next if $todo eq 'no';
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
       
       
        $to = "$to<$tpl> " unless $tpl eq "";
        $print = "$member\_";
        $print = "*$member\_" unless  $basetype{$to} ;
        
        print "\tout << \"$sep$member = \" << $print;\n"; 
        
        $sep = ", ";
    }        
    print "\tout << \"]\" << \"\\n\";\n";
    print "}\n\n";

     print <<EOF; 
$header
void $object\Attributes$p\::toxml(ostream& out)  const
{
     out <<  \"\\\"$tag\\\"\";
EOF
    
    foreach  my $param (@{$current->{parameter_list}}) 
    {      
         my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
       next if $todo eq 'no';
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $to = $current->{parameter}->{$param}->{attributes}->{to};
        my $tpl = $current->{parameter}->{$param}->{attributes}->{template};
       
       
        $to = "$to<$tpl> " unless $tpl eq "";
        if ( $basetype{$to} ) 
        {         	
             print "\t out << \", \\\"$name\\\":\";\n";
             print "\t niceprint(out,$member\_);\n";
        }
        elsif ( $classtype{$to}  )
		{
             print "\t out << \", \\\"$name\\\":\";\n";
             print "\t niceprint(out, *$member\_);\n";
		}
		else 
        {
            print "\t out << \", \\\"$name\\\":\";\n";
            print "\t $member\_->toxml(out);\n";       
        }
    }
    print "}\n";       

    foreach  my $param (@{$current->{parameter_list}}) 
    {     
         my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
       next if $todo eq 'no';
        my $name = $current->{parameter}->{$param}->{attributes}->{name};
        my $member = $current->{parameter}->{$param}->{attributes}->{member};
        my $from = $current->{parameter}->{$param}->{attributes}->{from};
        my $default = $current->{parameter}->{$param}->{attributes}->{default};
        my $migration = $current->{parameter}->{$param}->{migration}->{data};
        $from = $magtype{$from} if $magtype{$from};

        $default = "\"$default\"" if  $quote{$from} ;
     
        print <<EOF
static MagicsParameter<$from> $name("$name", $default, "$migration");
EOF
    } 
       
    foreach  my $param (@{$current->{parameter_list}}) 
    {     
        my $todo = $current->{parameter}->{$param}->{attributes}->{implemented};
        next if $todo eq 'no';
       
       
        foreach  my $option (@{$current->{parameter}->{$param}->{option_list}}) { 
        	my $include = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{include};
        	my $template = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{template};
        	my @templates = split("/", $template);
        	foreach my $t (@templates) { 
        		$includes_static->{$param}->{"$t.h"} = "$t.h";
        	}
        	$includes_static->{$param}->{$include} = $include unless $include eq "";
        }
       foreach  my $include (keys %{$includes_static->{$param}}) 
    	{     
        	print "#include \"$include\"\n";
    	} 
      
        foreach  my $option (@{$current->{parameter}->{$param}->{option_list}}) { 
        	my $class = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{name};
        	my $include = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{include};
        	my $fortran = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{fortran};
        	my $template = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{template};
        	my $xml = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{xml};
        	my $base = $current->{parameter}->{$param}->{attributes}->{to};  
        	my $templates = $current->{parameter}->{$param}->{option}->{$option}->{attributes}->{template};
			my @fortrans = split("/", $fortran);
        	if ($template eq "") {
        		for my $o (@fortrans) {
                    $n = $o;
                    $n =~ s/://;
                   
                   
        			print "static SimpleObjectMaker<$class, $base> $n\_$class(\"$o\");\n" if $o ne "";
        			print "static SimpleObjectMaker<$class, $base> $xml\_$class(\"$xml\");\n" if $xml ne "" && $xml ne $fortran;
				}
        	}
        	else {
        		my @templates = split("/", $template);	
        		for my $t (@templates) {
        			for my $o (@fortrans) {
                       
        				print "static SimpleObjectMaker<$class<$t>, $base<$t> > $o\_$class\_$t(\"$o\");\n" if $o ne "";
        	        	print "static SimpleObjectMaker<$class<$t>, $base<$t> > $xml\_$class\_$t(\"$xml\");\n" if $xml ne "" && $xml ne $fortran;
					}
        		}
        	}
        }
    }
}
