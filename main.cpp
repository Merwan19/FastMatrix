#include "main.h"

// a sample exported function

bool DLL_EXPORT inverseMatrix3(float *mat, float *res)
{
    float determinant=0, invDet;
    int i;

    for(i=0; i<3; i++)
        determinant = determinant + mat[i]*(mat[1 * 3 + (i+1)%3]*mat[2*3 + (i+2)%3] - mat[1*3 +(i+2)%3]*mat[2*3 +(i+1)%3]);

    if (determinant == 0.0)
        return false;

    invDet = 1 / determinant;

    res[0] = (mat[4] * mat[8] - mat[5] * mat[7]) * invDet;
    res[3] = (mat[5] * mat[6] - mat[3] * mat[8]) * invDet;
    res[6] = (mat[3] * mat[7] - mat[4] * mat[6]) * invDet;
    res[1] = (mat[2] * mat[7] - mat[1] * mat[8]) * invDet;
    res[4] = (mat[0] * mat[8] - mat[2] * mat[6]) * invDet;
    res[7] = (mat[1] * mat[6] - mat[0] * mat[7]) * invDet;
    res[2] = (mat[1] * mat[5] - mat[2] * mat[4]) * invDet;
    res[5] = (mat[2] * mat[3] - mat[0] * mat[5]) * invDet;
    res[8] = (mat[0] * mat[4] - mat[1] * mat[3]) * invDet;

    return true;

}

void DLL_EXPORT multiplyMatrix(float *mat, float *mat2, float *res, int matrixDimension)
{
    int i,j,k;
    float sum;
    for (i = 0; i < matrixDimension; i++)
    {
        for (j = 0; j < matrixDimension; j++)
        {
            sum = 0;
            for (k = 0; k < matrixDimension; k++)
            {
                sum = sum + mat[matrixDimension * i + k] * mat2[matrixDimension * k + j];
            }
            res[i * matrixDimension +j] = sum;
        }
    }
}




