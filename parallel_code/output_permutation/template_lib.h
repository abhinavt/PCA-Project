#if !defined(_MY_TEMP_H_)
#define _MY_TEMP_H_

/**
 * @filename  template_lib.h
 *
 * @brief     Defines the templates
 * 
 * @note      
 *
 * @author    Adil Sadik: ams2378@columbia.edu
 * 	      
 */

#include "includes.h"

typedef boost::dynamic_bitset<> lines;


/* type 2 templates */
struct template_2_1{
	
	struct t_2_original_1 matched;
	struct t_2_replace_1  replace;
}

struct template_2_2{
	
	struct t_2_original_2 matched;
	struct t_2_replace_2  replace;
}

struct t_2_original_1{

	lines controls_1 (string("10"));
	lines controls_2 (string("00"));
	lines target_1 (string("01"));
	lines target_2 (string("11"));
}

struct t_2_replace_1{

	lines controls_1 (string("00"));
	lines controls_2 (string("10"));
	lines target_1 (string("10"));
	lines target_2 (string("01"));
}

struct t_2_original_2{

	lines controls_1 (string("10"));
	lines controls_2 (string("00"));
	lines controls_3 (string("10"));
	lines target_1 (string("01"));
	lines target_2 (string("10"));
	lines target_3 (string("10"));
}

struct t_2_replace_2{

	lines controls_1 (string("00"));
	lines target_1 (string("11"));
}


/* type 3 templates */
struct template_3_1{
	
	struct t_3_original_1 matched;
	struct t_3_replace_1  replace;
}

struct template_3_2{
	
	struct t_3_original_2 matched;
	struct t_3_replace_2  replace;
}

struct template_3_3{
	
	struct t_3_original_3 matched;
	struct t_3_replace_3  replace;
}

struct t_3_original_1{

	lines controls_1 (string("000"));
	lines controls_2 (string("100"));
	lines controls_3 (string("110"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
	lines target_3 (string("001"));
}

struct t_3_replace_1{

	lines controls_1 (string("110"));
	lines controls_2 (string("000"));
	lines target_1 (string("001"));
	lines target_2 (string("010"));
}

struct t_3_original_2{

	lines controls_1 (string("010"));
	lines controls_2 (string("100"));
	lines controls_3 (string("100"));
	lines target_1 (string("001"));
	lines target_2 (string("001"));
	lines target_3 (string("010"));
}

struct t_3_replace_2{

	lines controls_1 (string("100"));
	lines controls_2 (string("010"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
}


struct t_3_original_3{

	lines controls_1 (string("100"));
	lines controls_2 (string("100"));
	lines controls_3 (string("110"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
	lines target_3 (string("001"));
}

struct t_3_replace_3{

	lines controls_1 (string("110"));
	lines controls_2 (string("100"));
	lines target_1 (string("001"));
	lines target_2 (string("010"));
}


/* type 4 templates*/
struct template_4_1{
	
	struct t_4_original_1 matched;
	struct t_4_replace_1  replace;
}

struct template_4_2{
	
	struct t_4_original_2 matched;
	struct t_4_replace_2  replace;
}

struct template_4_3{
	
	struct t_4_original_3 matched;
	struct t_4_replace_3  replace;
}

struct template_4_4{
	
	struct t_4_original_4 matched;
	struct t_4_replace_4  replace;
}

struct template_4_5{
	
	struct t_4_original_5 matched;
	struct t_4_replace_5  replace;
}

struct template_4_6{
	
	struct t_4_original_6 matched;
	struct t_4_replace_6  replace;
}


struct t_4_original_1{

	lines controls_1 (string("010"));
	lines controls_2 (string("100"));
	lines controls_3 (string("010"));
	lines target_1 (string("001"));
	lines target_2 (string("010"));
	lines target_3 (string("001"));
}

struct t_4_replace_1{

	lines controls_1 (string("100"));
	lines controls_2 (string("100"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
}

struct t_4_original_2{

	lines controls_1 (string("110"));
	lines controls_2 (string("100"));
	lines controls_3 (string("110"));
	lines target_1 (string("001"));
	lines target_2 (string("010"));
	lines target_3 (string("001"));
}

struct t_4_replace_2{

	lines controls_1 (string("100"));
	lines controls_2 (string("100"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
}


struct t_4_original_3{

	lines controls_1 (string("110"));
	lines controls_2 (string("000"));
	lines controls_3 (string("110"));
	lines target_1 (string("001"));
	lines target_2 (string("100"));
	lines target_3 (string("001"));
}

struct t_4_replace_3{

	lines controls_1 (string("000"));
	lines controls_2 (string("010"));
	lines target_1 (string("100"));
	lines target_2 (string("001"));
}


struct t_4_original_4{

	lines controls_1 (string("000"));
	lines controls_2 (string("110"));
	lines controls_3 (string("000"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
	lines target_3 (string("010"));
}

struct t_4_replace_4{

	lines controls_1 (string("110"));
	lines controls_2 (string("100"));
	lines target_1 (string("001"));
	lines target_2 (string("001"));
}


struct t_4_original_5{

	lines controls_1 (string("100"));
	lines controls_2 (string("110"));
	lines controls_3 (string("100"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
	lines target_3 (string("010"));
}

struct t_4_replace_5{

	lines controls_1 (string("110"));
	lines controls_2 (string("100"));
	lines target_1 (string("001"));
	lines target_2 (string("001"));
}


struct t_4_original_6{

	lines controls_1 (string("100"));
	lines controls_2 (string("010"));
	lines controls_3 (string("100"));
	lines target_1 (string("010"));
	lines target_2 (string("001"));
	lines target_3 (string("010"));
}

struct t_4_replace_6{

	lines controls_1 (string("010"));
	lines controls_2 (string("100"));
	lines target_1 (string("001"));
	lines target_2 (string("001"));
}

/* type 5 template */

struct template_5_1{
	
	struct t_5_original_1 matched;
	struct t_5_replace_1  replace;
}


struct t_5_original_1{

	lines controls_1 (string("110"));
	lines controls_2 (string("101"));
	lines controls_3 (string("110"));
	lines target_1 (string("001"));
	lines target_2 (string("010"));
	lines target_3 (string("001"));
}

struct t_5_replace_1{

	lines controls_1 (string("010"));
	lines controls_2 (string("101"));
	lines controls_3 (string("010"));
	lines target_1 (string("001"));
	lines target_2 (string("010"));
	lines target_3 (string("001"));
}

#endif
