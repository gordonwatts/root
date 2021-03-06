// @(#)root/pyroot:$Id$
// Author: Wim Lavrijsen, Apr 2004

#ifndef PYROOT_TMETHODHOLDER_H
#define PYROOT_TMETHODHOLDER_H

// Bindings
#include "Adapters.h"
#include "PyCallable.h"
#include "Utility.h"

// Standard
#include <string>
#include <vector>


namespace PyROOT {

/** Python side ROOT method
      @author  WLAV
      @date    15/03/2013
      @version 4.0
 */

   class TExecutor;
   class TConverter;

   class TMethodHolder : public PyCallable {
   public:
      TMethodHolder( const TScopeAdapter& klass, const TMemberAdapter& method );
      TMethodHolder( const TMethodHolder& );
      TMethodHolder& operator=( const TMethodHolder& );
      virtual ~TMethodHolder();

   public:
      virtual PyObject* GetSignature();
      virtual PyObject* GetPrototype();
      virtual Int_t GetPriority();

      virtual Int_t GetMaxArgs();
      virtual PyObject* GetArgSpec( Int_t iarg );
      virtual PyObject* GetArgDefault( Int_t iarg );
      virtual PyObject* GetScope();

      virtual PyCallable* Clone() { return new TMethodHolder( *this ); }

   public:
      virtual PyObject* operator()( ObjectProxy* self, PyObject* args, PyObject* kwds,
                                    Long_t user = 0, Bool_t release_gil = kFALSE );

      virtual Bool_t Initialize();
      virtual PyObject* FilterArgs( ObjectProxy*& self, PyObject* args, PyObject* kwds );
      virtual Bool_t SetMethodArgs( PyObject* args, Long_t user );
      virtual PyObject* Execute( void* self, Bool_t release_gil = kFALSE );

   protected:
      const TMemberAdapter& GetMethod() { return fMethod; }
      const TScopeAdapter& GetClass() { return fClass; }
      TExecutor* GetExecutor() { return fExecutor; }
      const std::string& GetSignatureString();

      virtual Bool_t InitExecutor_( TExecutor*& );

   private:
      void Copy_( const TMethodHolder& );
      void Destroy_() const;

      PyObject* CallFast( void*, Bool_t release_gil );
      PyObject* CallSafe( void*, Bool_t release_gil );

      Bool_t InitCallFunc_();

      void CreateSignature_();
      void SetPyError_( PyObject* msg );

   private:
   // representation
      TMemberAdapter fMethod;
      TScopeAdapter  fClass;
      CallFunc_t*    fMethodCall;
      TExecutor*     fExecutor;

      std::string fSignature;

   // call dispatch buffers
      std::vector< TConverter* > fConverters;

      std::vector< TParameter_t > fParameters;
      std::vector< void* >      fParamPtrs;

   // cached values
      Int_t        fArgsRequired;
      Long_t       fOffset;

   // admin
      Bool_t fIsInitialized;
   };

} // namespace PyROOT

#endif // !PYROOT_METHODHOLDER_H
