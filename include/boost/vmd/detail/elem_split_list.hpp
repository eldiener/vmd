#if !defined(BOOST_VMD_DETAIL_SPLIT_LIST_HPP)
#define BOOST_VMD_DETAIL_SPLIT_LIST_HPP

#include <boost/vmd/generic/elem.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/elem_split.hpp>

#define BOOST_VMD_DETAIL_ELEM_SPLIT_LIST(elem,...) \
	BOOST_VMD_DETAIL_ELEM_SPLIT(BOOST_VMD_ELEM(elem,__VA_ARGS__,BOOST_VMD_SPECIFIC_LIST),BOOST_VMD_TYPE_LIST) \
/**/

#define BOOST_VMD_DETAIL_ELEM_SPLIT_LIST_D(d,elem,...) \
	BOOST_VMD_DETAIL_ELEM_SPLIT_D(d,BOOST_VMD_ELEM_D(d,elem,__VA_ARGS__,BOOST_VMD_SPECIFIC_LIST),BOOST_VMD_TYPE_LIST) \
/**/

#endif /* BOOST_VMD_DETAIL_SPLIT_LIST_HPP */
