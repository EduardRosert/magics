/*
 * (C) Copyright 1996-2018 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#ifndef EMAGRAMGRID_H
#define EMAGRAMGRID_H

#include "magics.h"

#include "BasicSceneObject.h"
#include "TephiGrid.h"

namespace magics {

class EmagramGrid : public TephiGrid {
public:
    EmagramGrid();
    virtual ~EmagramGrid() override;

    // New Interface!
    void visit(DrawingVisitor&) override;
    void visit(LeftAxisVisitor&) override;
    void visit(RightAxisVisitor&) override;
    void visit(BottomAxisVisitor&) override;
    void visit(TopAxisVisitor&) override;
    void visit(SceneLayer& layer, vector<LayoutVisitor*>& visitors) override;

    void set(const map<string, string>& map) override { TephiGridAttributes::set(map); }
    void set(const XmlNode& node) override { TephiGridAttributes::set(node); }

protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream&) const override;
    map<double, PaperPoint> tTopLabels_;
    map<double, PaperPoint> tBottomLabels_;

private:
    //! Copy constructor - No copy allowed
    EmagramGrid(const EmagramGrid&);
    //! Overloaded << operator to copy - No copy allowed
    EmagramGrid& operator=(const EmagramGrid&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const EmagramGrid& p) {
        p.print(s);
        return s;
    }
};

}  // namespace magics

#endif  // EMAGRAMGRID_H
