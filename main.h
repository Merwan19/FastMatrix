#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <stdio.h>
/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

bool DLL_EXPORT inverseMatrix3(float *mat, float *res);
void DLL_EXPORT multiplyMatrix(float *mat, float *mat2, float *res, int matrixDimension);


#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
