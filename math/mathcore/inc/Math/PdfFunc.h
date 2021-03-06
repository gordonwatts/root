// @(#)root/mathcore:$Id$
// Authors: L. Moneta, A. Zsenei   08/2005

 /**********************************************************************
  *                                                                    *
  * Copyright (c) 2004 ROOT Foundation,  CERN/PH-SFT                   *
  *                                                                    *
  *                                                                    *
  **********************************************************************/

/** 
    Header file declaring the pdf distributions present in both 
    MathCore and optionally MathMore. 
    The MathMore ones are included only if ROOT has been built with MathMore. 
*/


#ifndef ROOT_Math_PdfFunc
#define ROOT_Math_PdfFunc


#ifndef ROOT_RConfigure
#include "RConfigure.h"
#endif

// all cdf are in mathcore now
#ifndef ROOT_Math_PdfFuncMathCore
#include "Math/PdfFuncMathCore.h"
#endif

// // include distributions from MathMore when is there
// #ifdef R__HAS_MATHMORE  

// // extra cdf in MathMore
// #ifndef ROOT_Math_PdfFuncMathMore
// #include "Math/PdfFuncMathMore.h"
// #endif


// #endif

#endif  // ROOT_Math_PdfFunc
