#include <iostream>
#include <string>

/*	6.39.
* 
*	(a) : second version matches with const arguments more. 
*		: if we call function clac with const arguments, then second version will be called.
* 
*	(b) : wrong. 
*		: overloaded functions different only with return type can't be exist.
*	
*	(c) : double type arguemnts now get more matching version of function for them.
*		: before the second one, double type argument could be matched with first one, but transition of type occured.
*		: from now on, double type argument is no longer need to be changed into int type.
*/