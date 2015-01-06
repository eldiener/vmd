#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/identifier/is_identifier.hpp>
#include <boost/vmd/seq/is_seq.hpp>
#include <boost/vmd/generic/to_array.hpp>
#include <boost/vmd/types.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/array/size.hpp>
#include <boost/preprocessor/list/at.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)
  #define BOOST_VMD_DETECT_ggh_ggh
  #define BOOST_VMD_REGISTER_dvd (dvd)
  #define BOOST_VMD_DETECT_dvd_dvd
  
  #define ANIDENTIFIER ggh
  #define ANIDENTIFIER2 dvd
  #define ANUMBER 249
  #define ANUMBER2 17
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER2 ASEQ ALIST ANUMBER ATUPLE
  #define ASEQUENCE3 ASEQ ANUMBER2 ATUPLE
  #define ASEQUENCE4
  
  /* TO_ARRAY */
  
  BOOST_TEST(BOOST_VMD_EQUAL_TYPE(BOOST_PP_TUPLE_ELEM(0,BOOST_PP_ARRAY_ELEM(3,BOOST_VMD_TO_ARRAY(ASEQUENCE,BOOST_VMD_RETURN_TYPE))),BOOST_VMD_TYPE_IDENTIFIER));
  BOOST_TEST(BOOST_VMD_IS_IDENTIFIER(BOOST_PP_TUPLE_ELEM(1,BOOST_PP_ARRAY_ELEM(0,BOOST_VMD_TO_ARRAY(ASEQUENCE2,BOOST_VMD_RETURN_TYPE))),dvd));
  BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(1,BOOST_PP_ARRAY_ELEM(1,BOOST_VMD_TO_ARRAY(ASEQUENCE3,BOOST_VMD_RETURN_TYPE))),17);
  BOOST_TEST_EQ(BOOST_PP_ARRAY_SIZE(BOOST_VMD_TO_ARRAY(ASEQUENCE4,BOOST_VMD_RETURN_TYPE)),0);
  
  /* TO_ARRAY_DATA */
  
  BOOST_TEST_EQ(BOOST_PP_LIST_AT(BOOST_PP_ARRAY_ELEM(2,BOOST_VMD_TO_ARRAY(ASEQUENCE2)),1),1);
  BOOST_TEST(BOOST_VMD_IS_SEQ(BOOST_PP_ARRAY_ELEM(0,BOOST_VMD_TO_ARRAY(ASEQUENCE3))));
  BOOST_TEST_EQ(BOOST_PP_ARRAY_ELEM(2,BOOST_PP_ARRAY_ELEM(4,BOOST_VMD_TO_ARRAY(ASEQUENCE))),38);
  BOOST_TEST_EQ(BOOST_PP_ARRAY_SIZE(BOOST_VMD_TO_ARRAY(ASEQUENCE4)),0);
  
#endif

  return boost::report_errors();
  
  }
