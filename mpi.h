
 
 #ifndef _MPI_H
 #define _MPI_H
 
 
 #include <stdio.h>								//For Dependencies
 #include "crypto.h"
 

 #define MPI_INT_SIZE sizeof(uint_t)						 //Size of the sub data type
 
 																		//Error code checking
 #define MPI_CHECK(f) if((error = f) != NO_ERROR) goto end
 

 #define mpiIsEven(a) !mpiGetBitValue(a, 0)
 #define mpiIsOdd(a) mpiGetBitValue(a, 0)
 
 
 
 typedef struct
 {
    int_t sign;
    uint_t size;
    uint_t *data;
 } Mpi;
 
 
 //MPI related functions
 void mpiInit(Mpi *r);
 void mpiFree(Mpi *r);
 
 error_t mpiGrow(Mpi *r, uint_t size);
 
 uint_t mpiGetLength(const Mpi *a);
 uint_t mpiGetByteLength(const Mpi *a);
 uint_t mpiGetBitLength(const Mpi *a);
 
 error_t mpiSetBitValue(Mpi *r, uint_t index, uint_t value);
 uint_t mpiGetBitValue(const Mpi *a, uint_t index);
 
 int_t mpiComp(const Mpi *a, const Mpi *b);
 int_t mpiCompInt(const Mpi *a, int_t b);
 int_t mpiCompAbs(const Mpi *a, const Mpi *b);
 
 error_t mpiCopy(Mpi *r, const Mpi *a);
 error_t mpiSetValue(Mpi *a, int_t b);
 
 error_t mpiRand(Mpi *r, uint_t length, const PrngAlgo *prngAlgo, void *prngContext);
 
 error_t mpiReadRaw(Mpi *r, const uint8_t *data, uint_t length);
 error_t mpiWriteRaw(const Mpi *a, uint8_t *data, uint_t length);
 
 error_t mpiAdd(Mpi *r, const Mpi *a, const Mpi *b);
 error_t mpiAddInt(Mpi *r, const Mpi *a, int_t b);
 
 error_t mpiSub(Mpi *r, const Mpi *a, const Mpi *b);
 error_t mpiSubInt(Mpi *r, const Mpi *a, int_t b);
 
 error_t mpiAddAbs(Mpi *r, const Mpi *a, const Mpi *b);
 error_t mpiSubAbs(Mpi *r, const Mpi *a, const Mpi *b);
 
 error_t mpiShiftLeft(Mpi *r, uint_t n);
 error_t mpiShiftRight(Mpi *r, uint_t n);
 
 error_t mpiMul(Mpi *r, const Mpi *a, const Mpi *b);
 error_t mpiMulInt(Mpi *r, const Mpi *a, int_t b);
 
 error_t mpiDiv(Mpi *q, Mpi *r, const Mpi *a, const Mpi *b);
 error_t mpiDivInt(Mpi *q, Mpi *r, const Mpi *a, int_t b);
 
 error_t mpiMod(Mpi *r, const Mpi *a, const Mpi *p);
 error_t mpiAddMod(Mpi *r, const Mpi *a, const Mpi *b, const Mpi *p);
 error_t mpiSubMod(Mpi *r, const Mpi *a, const Mpi *b, const Mpi *p);
 error_t mpiMulMod(Mpi *r, const Mpi *a, const Mpi *b, const Mpi *p);
 error_t mpiInvMod(Mpi *r, const Mpi *a, const Mpi *p);
 error_t mpiExpMod(Mpi *r, const Mpi *a, const Mpi *e, const Mpi *p);
 
 error_t mpiMontgomeryMul(Mpi *r, const Mpi *a, const Mpi *b, uint_t k, const Mpi *p, Mpi *t);
 error_t mpiMontgomeryRed(Mpi *r, const Mpi *a, uint_t k, const Mpi *p, Mpi *t);
 
 void mpiMulAccCore(uint_t *r, const uint_t *a, int_t m, const uint_t b);
 
 void mpiDump(FILE *stream, const char_t *prepend, const Mpi *a);
 
 #endif
