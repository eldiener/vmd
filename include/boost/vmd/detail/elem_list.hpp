#if !defined(BOOST_VMD_DETAIL_ELEM_LIST_HPP)
#define BOOST_VMD_DETAIL_ELEM_LIST_HPP

#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/vmd/generic/elem.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/elem.hpp>
#include <boost/vmd/detail/elem_split_list.hpp>
#include <boost/vmd/detail/list.hpp>
#include <boost/vmd/detail/mods.hpp>
#include <boost/vmd/detail/only_after.hpp>

#define BOOST_VMD_DETAIL_ELEM_LIST_PROCESS(elem,...) \
	BOOST_VMD_DETAIL_ELEM(BOOST_VMD_ELEM(elem,__VA_ARGS__,BOOST_VMD_PARSE_LIST),BOOST_VMD_TYPE_LIST) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_PROCESS_D(d,elem,...) \
	BOOST_VMD_DETAIL_ELEM_D(d,BOOST_VMD_ELEM_D(d,elem,__VA_ARGS__,BOOST_VMD_PARSE_LIST),BOOST_VMD_TYPE_LIST) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_ONLY(elem,...) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_ELEM_SPLIT_LIST(elem,BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__),BOOST_VMD_RETURN_AFTER)) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_ONLY_D(d,elem,...) \
	BOOST_PP_TUPLE_ELEM(1,BOOST_VMD_DETAIL_ELEM_SPLIT_LIST_D(d,elem,BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__),BOOST_VMD_RETURN_AFTER)) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_E0_RES(res,...) \
	BOOST_VMD_IDENTITY_RESULT \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_DETAIL_ONLY_AFTER(__VA_ARGS__), \
			BOOST_PP_TUPLE_ELEM, \
			BOOST_VMD_IDENTITY(res) \
			) \
		(1,res) \
		) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_E0_RES_D(d,res,...) \
	BOOST_VMD_IDENTITY_RESULT \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_DETAIL_ONLY_AFTER_D(d,__VA_ARGS__), \
			BOOST_PP_TUPLE_ELEM, \
			BOOST_VMD_IDENTITY(res) \
			) \
		(1,res) \
		) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_E0(elem,...) \
	BOOST_VMD_DETAIL_ELEM_LIST_E0_RES \
		( \
		BOOST_VMD_DETAIL_LIST(__VA_ARGS__), \
		__VA_ARGS__ \
		) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_E0_D(d,elem,...) \
	BOOST_VMD_DETAIL_ELEM_LIST_E0_RES_D \
		( \
		d, \
		BOOST_VMD_DETAIL_LIST(__VA_ARGS__), \
		__VA_ARGS__ \
		) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_MODS(mods,elem,...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_MODS_IS_RESULT_ONLY_AFTER(mods), \
		BOOST_VMD_DETAIL_ELEM_LIST_ONLY, \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_DETAIL_MODS_IS_RESULT_AFTER(mods), \
			BOOST_VMD_DETAIL_ELEM_SPLIT_LIST, \
			BOOST_VMD_DETAIL_ELEM_LIST_PROCESS \
			) \
		) \
	(elem,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_MODS_D(d,mods,elem,...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_MODS_IS_RESULT_ONLY_AFTER(mods), \
		BOOST_VMD_DETAIL_ELEM_LIST_ONLY_D, \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_DETAIL_MODS_IS_RESULT_AFTER(mods), \
			BOOST_VMD_DETAIL_ELEM_SPLIT_LIST_D, \
			BOOST_VMD_DETAIL_ELEM_LIST_PROCESS_D \
			) \
		) \
	(d,elem,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_NOTZ(elem,...) \
	BOOST_VMD_DETAIL_ELEM_LIST_MODS \
		( \
		BOOST_VMD_DETAIL_NEW_MODS(BOOST_VMD_ALLOW_AFTER,__VA_ARGS__), \
		elem, \
		__VA_ARGS__ \
		) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_NOTZ_D(d,elem,...) \
	BOOST_VMD_DETAIL_ELEM_LIST_MODS_D \
		( \
		d, \
		BOOST_VMD_DETAIL_NEW_MODS_D(d,BOOST_VMD_ALLOW_AFTER,__VA_ARGS__), \
		elem, \
		__VA_ARGS__ \
		) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST(elem,...) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL(elem,0), \
		BOOST_VMD_DETAIL_ELEM_LIST_E0, \
		BOOST_VMD_DETAIL_ELEM_LIST_NOTZ \
		) \
	(elem,__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_ELEM_LIST_D(d,elem,...) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL_D(d,elem,0), \
		BOOST_VMD_DETAIL_ELEM_LIST_E0_D, \
		BOOST_VMD_DETAIL_ELEM_LIST_NOTZ_D \
		) \
	(d,elem,__VA_ARGS__) \
/**/

#endif /* BOOST_VMD_DETAIL_ELEM_LIST_HPP */
