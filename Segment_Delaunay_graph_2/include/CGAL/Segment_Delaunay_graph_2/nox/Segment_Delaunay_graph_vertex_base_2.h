// Copyright (c) 2003,2004,2005  INRIA Sophia-Antipolis (France) and
// Notre Dame University (U.S.A.).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@cse.nd.edu>




#ifndef CGAL_SEGMENT_DELAUNAY_GRAPH_NOX_VERTEX_BASE_2_H
#define CGAL_SEGMENT_DELAUNAY_GRAPH_NOX_VERTEX_BASE_2_H

#include <CGAL/Segment_Delaunay_graph_2/basic.h>

#include <CGAL/Triangulation_ds_vertex_base_2.h>
#include <CGAL/Segment_Delaunay_graph_2/nox/Segment_Delaunay_graph_site_2.h>



CGAL_BEGIN_NAMESPACE

template < class Gt, class Vb = Triangulation_ds_vertex_base_2<> >
class Segment_Delaunay_graph_vertex_base_2
  : public Vb
{
private:
  typedef typename Vb::Triangulation_data_structure  D_S;
  typedef Vb                                         Base;

public:
  // TYPES
  //------
  typedef Gt                                       Geom_traits;
  typedef typename Geom_traits::Site_2             Site_2;
  typedef typename Geom_traits::Point_2            Point_2;
  typedef D_S                                      Data_structure;
  
  typedef typename D_S::Face_handle                Face_handle;
  typedef typename D_S::Vertex_handle              Vertex_handle;


  template < typename DS2 >
  struct Rebind_TDS {
    typedef typename Vb::template Rebind_TDS<DS2>::Other    Vb2;
    typedef Segment_Delaunay_graph_vertex_base_2<Gt,Vb2>    Other;
  };

  
  Segment_Delaunay_graph_vertex_base_2 () : Vb(), s_() {}
    
  Segment_Delaunay_graph_vertex_base_2(const Site_2& s,	Face_handle f)
    : Vb(f), s_(s)  {}

  void set_site(const Site_2& s) { s_ = s; }

  void set_point(const Point_2& p) { s_ = Site_2::construct_site_2(p); }

  const Site_2& site() const { return s_; }
  const Point_2& point() const {
    CGAL_precondition( s_.is_point() );
    return s_.point();
  }

  //the following trivial is_valid to allow
  // the user of derived face base classes 
  // to add their own purpose checking
  bool is_valid(bool /* verbose */ = false, int /* level */ = 0) const
  { return true; }

private:
  Site_2 s_;
  //  std::list<Vb>  adjseg_list; // list of adjacent segments; this is
  // important when I want to do deletions
};


CGAL_END_NAMESPACE 

#endif // CGAL_SEGMENT_DELAUNAY_GRAPH_NOX_VERTEX_BASE_2_H