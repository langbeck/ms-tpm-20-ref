/* Microsoft Reference Implementation for TPM 2.0
 *
 *  The copyright in this software is being made available under the BSD License,
 *  included below. This software may be subject to other third party and
 *  contributor rights, including patent rights, and no such rights are granted
 *  under this license.
 *
 *  Copyright (c) Microsoft Corporation
 *
 *  All rights reserved.
 *
 *  BSD License
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  Redistributions of source code must retain the above copyright notice, this list
 *  of conditions and the following disclaimer.
 *
 *  Redistributions in binary form must reproduce the above copyright notice, this
 *  list of conditions and the following disclaimer in the documentation and/or other
 *  materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ""AS IS""
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*(Auto)
    Automatically Generated by TpmPrototypes version 2.2 February 10, 2016 
    Date: Sep  9, 2016 Time: 01:03:57 PM  
*/

#ifndef    _MSBNMALLOC_FP_H_
#define    _MSBNMALLOC_FP_H_

#if MATH_LIB == MSBN

#ifdef COLLECT_METRICS
//*** FindMetric()
// This is called when a context is created for a function. It searches to find the
// function name and if found, it associates the context address with the name. This
// allows the entry to be found using the
memoryMetric *
FindMetric(
    LPCSTR           name
    );
#endif
// The context structures are contained in the caller's space. This function links
// and initializes them.
//

//*** MsBnContextStart()
pMsbnCtx
MsBnContextStart(
    LPCSTR               name,
    crypt_uword_t       *pool,      // IN: the data pool for temps
    size_t               uwords     // IN: number of crypt_uwords in 'pool'
    );

void* WINAPI mp_alloc_temp(
    DWORDREGC cb,
    LPCSTR    pszSource_info,
    bigctx_t  *pCtx);

void WINAPI mp_free_temp(
    __in                  void     *pVoid,
    __in_opt              LPCSTR    pszSource_info,
    __in                  bigctx_t  *pCtx);

void WINAPI SetMpErrno(mp_errno_tc code, bigctx_t *pBignumCtxt);

void WINAPI SetMpErrno_clue1(__in mp_errno_tc code, __in_opt const char *hint,
                             PBIGCTX_ARG);
#endif


#endif  // _MSBNMALLOC_FP_H_
