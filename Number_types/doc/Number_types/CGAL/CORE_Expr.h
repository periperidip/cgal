
namespace CGAL {
namespace CORE {
/*!
\ingroup nt_core

The class `CORE::Expr` provides exact computation over the subset of real 
numbers that contains integers, and which is closed by the operations 
\f$ +,-,\times,/,\sqrt{}\f$ and \f$ kth\_root\f$. Operations and comparisons 
between objects of this type are guaranteed to be exact. 
This number type is provided by the 
<span class="textsc">Core</span> library \cite klpy-clp-99. 

\cgal defines the necessary functions so that this class complies to the 
requirements on number types. 

\models ::FieldWithRootOf 
\models ::RealEmbeddable 
\models ::FromDoubleConstructible 

*/
class Expr {
}; /* end CORE::Expr */
} /* end namespace CORE */
} /* end namespace CGAL */
