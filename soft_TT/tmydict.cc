// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME tmydict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "tunpacker.h"
#include "thldevent.h"
#include "thldsubevent.h"
#include "tevent.h"
#include "teventhdr.h"
#include "trpclookuptable.h"
#include "thit.h"
#include "trpccalpar.h"
#include "trpcraw.h"
#include "trpcrawf.h"
#include "trpchit.h"
#include "trpchitf.h"
#include "trpcsaeta.h"
#include "trpcsaetaf.h"
#include "tactivecells.h"
#include "ttmatrix.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HldSubEvent(void *p = 0);
   static void *newArray_HldSubEvent(Long_t size, void *p);
   static void delete_HldSubEvent(void *p);
   static void deleteArray_HldSubEvent(void *p);
   static void destruct_HldSubEvent(void *p);
   static void streamer_HldSubEvent(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HldSubEvent*)
   {
      ::HldSubEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HldSubEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HldSubEvent", ::HldSubEvent::Class_Version(), "thldsubevent.h", 15,
                  typeid(::HldSubEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HldSubEvent::Dictionary, isa_proxy, 16,
                  sizeof(::HldSubEvent) );
      instance.SetNew(&new_HldSubEvent);
      instance.SetNewArray(&newArray_HldSubEvent);
      instance.SetDelete(&delete_HldSubEvent);
      instance.SetDeleteArray(&deleteArray_HldSubEvent);
      instance.SetDestructor(&destruct_HldSubEvent);
      instance.SetStreamerFunc(&streamer_HldSubEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HldSubEvent*)
   {
      return GenerateInitInstanceLocal((::HldSubEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HldSubEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Hit(void *p = 0);
   static void *newArray_Hit(Long_t size, void *p);
   static void delete_Hit(void *p);
   static void deleteArray_Hit(void *p);
   static void destruct_Hit(void *p);
   static void streamer_Hit(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Hit*)
   {
      ::Hit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Hit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Hit", ::Hit::Class_Version(), "thit.h", 9,
                  typeid(::Hit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Hit::Dictionary, isa_proxy, 16,
                  sizeof(::Hit) );
      instance.SetNew(&new_Hit);
      instance.SetNewArray(&newArray_Hit);
      instance.SetDelete(&delete_Hit);
      instance.SetDeleteArray(&deleteArray_Hit);
      instance.SetDestructor(&destruct_Hit);
      instance.SetStreamerFunc(&streamer_Hit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Hit*)
   {
      return GenerateInitInstanceLocal((::Hit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Hit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_EventHdr(void *p = 0);
   static void *newArray_EventHdr(Long_t size, void *p);
   static void delete_EventHdr(void *p);
   static void deleteArray_EventHdr(void *p);
   static void destruct_EventHdr(void *p);
   static void streamer_EventHdr(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventHdr*)
   {
      ::EventHdr *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventHdr >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EventHdr", ::EventHdr::Class_Version(), "teventhdr.h", 16,
                  typeid(::EventHdr), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EventHdr::Dictionary, isa_proxy, 16,
                  sizeof(::EventHdr) );
      instance.SetNew(&new_EventHdr);
      instance.SetNewArray(&newArray_EventHdr);
      instance.SetDelete(&delete_EventHdr);
      instance.SetDeleteArray(&deleteArray_EventHdr);
      instance.SetDestructor(&destruct_EventHdr);
      instance.SetStreamerFunc(&streamer_EventHdr);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventHdr*)
   {
      return GenerateInitInstanceLocal((::EventHdr*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EventHdr*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Event(void *p = 0);
   static void *newArray_Event(Long_t size, void *p);
   static void delete_Event(void *p);
   static void deleteArray_Event(void *p);
   static void destruct_Event(void *p);
   static void streamer_Event(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Event*)
   {
      ::Event *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Event >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Event", ::Event::Class_Version(), "tevent.h", 33,
                  typeid(::Event), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Event::Dictionary, isa_proxy, 16,
                  sizeof(::Event) );
      instance.SetNew(&new_Event);
      instance.SetNewArray(&newArray_Event);
      instance.SetDelete(&delete_Event);
      instance.SetDeleteArray(&deleteArray_Event);
      instance.SetDestructor(&destruct_Event);
      instance.SetStreamerFunc(&streamer_Event);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Event*)
   {
      return GenerateInitInstanceLocal((::Event*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Event*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_HldEvent(void *p = 0);
   static void *newArray_HldEvent(Long_t size, void *p);
   static void delete_HldEvent(void *p);
   static void deleteArray_HldEvent(void *p);
   static void destruct_HldEvent(void *p);
   static void streamer_HldEvent(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HldEvent*)
   {
      ::HldEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HldEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HldEvent", ::HldEvent::Class_Version(), "thldevent.h", 32,
                  typeid(::HldEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HldEvent::Dictionary, isa_proxy, 16,
                  sizeof(::HldEvent) );
      instance.SetNew(&new_HldEvent);
      instance.SetNewArray(&newArray_HldEvent);
      instance.SetDelete(&delete_HldEvent);
      instance.SetDeleteArray(&deleteArray_HldEvent);
      instance.SetDestructor(&destruct_HldEvent);
      instance.SetStreamerFunc(&streamer_HldEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HldEvent*)
   {
      return GenerateInitInstanceLocal((::HldEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HldEvent*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Unpacker(void *p = 0);
   static void *newArray_Unpacker(Long_t size, void *p);
   static void delete_Unpacker(void *p);
   static void deleteArray_Unpacker(void *p);
   static void destruct_Unpacker(void *p);
   static void streamer_Unpacker(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Unpacker*)
   {
      ::Unpacker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Unpacker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Unpacker", ::Unpacker::Class_Version(), "tunpacker.h", 21,
                  typeid(::Unpacker), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Unpacker::Dictionary, isa_proxy, 16,
                  sizeof(::Unpacker) );
      instance.SetNew(&new_Unpacker);
      instance.SetNewArray(&newArray_Unpacker);
      instance.SetDelete(&delete_Unpacker);
      instance.SetDeleteArray(&deleteArray_Unpacker);
      instance.SetDestructor(&destruct_Unpacker);
      instance.SetStreamerFunc(&streamer_Unpacker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Unpacker*)
   {
      return GenerateInitInstanceLocal((::Unpacker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Unpacker*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RpcLookupTable(void *p = 0);
   static void *newArray_RpcLookupTable(Long_t size, void *p);
   static void delete_RpcLookupTable(void *p);
   static void deleteArray_RpcLookupTable(void *p);
   static void destruct_RpcLookupTable(void *p);
   static void streamer_RpcLookupTable(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RpcLookupTable*)
   {
      ::RpcLookupTable *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RpcLookupTable >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RpcLookupTable", ::RpcLookupTable::Class_Version(), "trpclookuptable.h", 8,
                  typeid(::RpcLookupTable), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RpcLookupTable::Dictionary, isa_proxy, 16,
                  sizeof(::RpcLookupTable) );
      instance.SetNew(&new_RpcLookupTable);
      instance.SetNewArray(&newArray_RpcLookupTable);
      instance.SetDelete(&delete_RpcLookupTable);
      instance.SetDeleteArray(&deleteArray_RpcLookupTable);
      instance.SetDestructor(&destruct_RpcLookupTable);
      instance.SetStreamerFunc(&streamer_RpcLookupTable);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RpcLookupTable*)
   {
      return GenerateInitInstanceLocal((::RpcLookupTable*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RpcLookupTable*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcCalPar(void *p = 0);
   static void *newArray_TRpcCalPar(Long_t size, void *p);
   static void delete_TRpcCalPar(void *p);
   static void deleteArray_TRpcCalPar(void *p);
   static void destruct_TRpcCalPar(void *p);
   static void streamer_TRpcCalPar(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcCalPar*)
   {
      ::TRpcCalPar *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcCalPar >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcCalPar", ::TRpcCalPar::Class_Version(), "trpccalpar.h", 8,
                  typeid(::TRpcCalPar), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcCalPar::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcCalPar) );
      instance.SetNew(&new_TRpcCalPar);
      instance.SetNewArray(&newArray_TRpcCalPar);
      instance.SetDelete(&delete_TRpcCalPar);
      instance.SetDeleteArray(&deleteArray_TRpcCalPar);
      instance.SetDestructor(&destruct_TRpcCalPar);
      instance.SetStreamerFunc(&streamer_TRpcCalPar);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcCalPar*)
   {
      return GenerateInitInstanceLocal((::TRpcCalPar*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcCalPar*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcRaw(void *p = 0);
   static void *newArray_TRpcRaw(Long_t size, void *p);
   static void delete_TRpcRaw(void *p);
   static void deleteArray_TRpcRaw(void *p);
   static void destruct_TRpcRaw(void *p);
   static void streamer_TRpcRaw(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcRaw*)
   {
      ::TRpcRaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcRaw >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcRaw", ::TRpcRaw::Class_Version(), "trpcraw.h", 6,
                  typeid(::TRpcRaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcRaw::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcRaw) );
      instance.SetNew(&new_TRpcRaw);
      instance.SetNewArray(&newArray_TRpcRaw);
      instance.SetDelete(&delete_TRpcRaw);
      instance.SetDeleteArray(&deleteArray_TRpcRaw);
      instance.SetDestructor(&destruct_TRpcRaw);
      instance.SetStreamerFunc(&streamer_TRpcRaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcRaw*)
   {
      return GenerateInitInstanceLocal((::TRpcRaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcRaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcRawF(void *p = 0);
   static void *newArray_TRpcRawF(Long_t size, void *p);
   static void delete_TRpcRawF(void *p);
   static void deleteArray_TRpcRawF(void *p);
   static void destruct_TRpcRawF(void *p);
   static void streamer_TRpcRawF(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcRawF*)
   {
      ::TRpcRawF *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcRawF >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcRawF", ::TRpcRawF::Class_Version(), "trpcrawf.h", 23,
                  typeid(::TRpcRawF), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcRawF::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcRawF) );
      instance.SetNew(&new_TRpcRawF);
      instance.SetNewArray(&newArray_TRpcRawF);
      instance.SetDelete(&delete_TRpcRawF);
      instance.SetDeleteArray(&deleteArray_TRpcRawF);
      instance.SetDestructor(&destruct_TRpcRawF);
      instance.SetStreamerFunc(&streamer_TRpcRawF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcRawF*)
   {
      return GenerateInitInstanceLocal((::TRpcRawF*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcRawF*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcHit(void *p = 0);
   static void *newArray_TRpcHit(Long_t size, void *p);
   static void delete_TRpcHit(void *p);
   static void deleteArray_TRpcHit(void *p);
   static void destruct_TRpcHit(void *p);
   static void streamer_TRpcHit(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcHit*)
   {
      ::TRpcHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcHit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcHit", ::TRpcHit::Class_Version(), "trpchit.h", 6,
                  typeid(::TRpcHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcHit::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcHit) );
      instance.SetNew(&new_TRpcHit);
      instance.SetNewArray(&newArray_TRpcHit);
      instance.SetDelete(&delete_TRpcHit);
      instance.SetDeleteArray(&deleteArray_TRpcHit);
      instance.SetDestructor(&destruct_TRpcHit);
      instance.SetStreamerFunc(&streamer_TRpcHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcHit*)
   {
      return GenerateInitInstanceLocal((::TRpcHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcHit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TActiveCells(void *p = 0);
   static void *newArray_TActiveCells(Long_t size, void *p);
   static void delete_TActiveCells(void *p);
   static void deleteArray_TActiveCells(void *p);
   static void destruct_TActiveCells(void *p);
   static void streamer_TActiveCells(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TActiveCells*)
   {
      ::TActiveCells *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TActiveCells >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TActiveCells", ::TActiveCells::Class_Version(), "tactivecells.h", 10,
                  typeid(::TActiveCells), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TActiveCells::Dictionary, isa_proxy, 16,
                  sizeof(::TActiveCells) );
      instance.SetNew(&new_TActiveCells);
      instance.SetNewArray(&newArray_TActiveCells);
      instance.SetDelete(&delete_TActiveCells);
      instance.SetDeleteArray(&deleteArray_TActiveCells);
      instance.SetDestructor(&destruct_TActiveCells);
      instance.SetStreamerFunc(&streamer_TActiveCells);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TActiveCells*)
   {
      return GenerateInitInstanceLocal((::TActiveCells*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TActiveCells*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcHitF(void *p = 0);
   static void *newArray_TRpcHitF(Long_t size, void *p);
   static void delete_TRpcHitF(void *p);
   static void deleteArray_TRpcHitF(void *p);
   static void destruct_TRpcHitF(void *p);
   static void streamer_TRpcHitF(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcHitF*)
   {
      ::TRpcHitF *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcHitF >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcHitF", ::TRpcHitF::Class_Version(), "trpchitf.h", 22,
                  typeid(::TRpcHitF), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcHitF::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcHitF) );
      instance.SetNew(&new_TRpcHitF);
      instance.SetNewArray(&newArray_TRpcHitF);
      instance.SetDelete(&delete_TRpcHitF);
      instance.SetDeleteArray(&deleteArray_TRpcHitF);
      instance.SetDestructor(&destruct_TRpcHitF);
      instance.SetStreamerFunc(&streamer_TRpcHitF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcHitF*)
   {
      return GenerateInitInstanceLocal((::TRpcHitF*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcHitF*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcSaeta(void *p = 0);
   static void *newArray_TRpcSaeta(Long_t size, void *p);
   static void delete_TRpcSaeta(void *p);
   static void deleteArray_TRpcSaeta(void *p);
   static void destruct_TRpcSaeta(void *p);
   static void streamer_TRpcSaeta(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcSaeta*)
   {
      ::TRpcSaeta *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcSaeta >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcSaeta", ::TRpcSaeta::Class_Version(), "trpcsaeta.h", 7,
                  typeid(::TRpcSaeta), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcSaeta::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcSaeta) );
      instance.SetNew(&new_TRpcSaeta);
      instance.SetNewArray(&newArray_TRpcSaeta);
      instance.SetDelete(&delete_TRpcSaeta);
      instance.SetDeleteArray(&deleteArray_TRpcSaeta);
      instance.SetDestructor(&destruct_TRpcSaeta);
      instance.SetStreamerFunc(&streamer_TRpcSaeta);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcSaeta*)
   {
      return GenerateInitInstanceLocal((::TRpcSaeta*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcSaeta*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TRpcSaetaF(void *p = 0);
   static void *newArray_TRpcSaetaF(Long_t size, void *p);
   static void delete_TRpcSaetaF(void *p);
   static void deleteArray_TRpcSaetaF(void *p);
   static void destruct_TRpcSaetaF(void *p);
   static void streamer_TRpcSaetaF(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRpcSaetaF*)
   {
      ::TRpcSaetaF *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRpcSaetaF >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRpcSaetaF", ::TRpcSaetaF::Class_Version(), "trpcsaetaf.h", 18,
                  typeid(::TRpcSaetaF), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRpcSaetaF::Dictionary, isa_proxy, 16,
                  sizeof(::TRpcSaetaF) );
      instance.SetNew(&new_TRpcSaetaF);
      instance.SetNewArray(&newArray_TRpcSaetaF);
      instance.SetDelete(&delete_TRpcSaetaF);
      instance.SetDeleteArray(&deleteArray_TRpcSaetaF);
      instance.SetDestructor(&destruct_TRpcSaetaF);
      instance.SetStreamerFunc(&streamer_TRpcSaetaF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRpcSaetaF*)
   {
      return GenerateInitInstanceLocal((::TRpcSaetaF*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRpcSaetaF*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TTMatrix(void *p = 0);
   static void *newArray_TTMatrix(Long_t size, void *p);
   static void delete_TTMatrix(void *p);
   static void deleteArray_TTMatrix(void *p);
   static void destruct_TTMatrix(void *p);
   static void streamer_TTMatrix(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTMatrix*)
   {
      ::TTMatrix *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTMatrix >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TTMatrix", ::TTMatrix::Class_Version(), "ttmatrix.h", 8,
                  typeid(::TTMatrix), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TTMatrix::Dictionary, isa_proxy, 16,
                  sizeof(::TTMatrix) );
      instance.SetNew(&new_TTMatrix);
      instance.SetNewArray(&newArray_TTMatrix);
      instance.SetDelete(&delete_TTMatrix);
      instance.SetDeleteArray(&deleteArray_TTMatrix);
      instance.SetDestructor(&destruct_TTMatrix);
      instance.SetStreamerFunc(&streamer_TTMatrix);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTMatrix*)
   {
      return GenerateInitInstanceLocal((::TTMatrix*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TTMatrix*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HldSubEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HldSubEvent::Class_Name()
{
   return "HldSubEvent";
}

//______________________________________________________________________________
const char *HldSubEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HldSubEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HldSubEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HldSubEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HldSubEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HldSubEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HldSubEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HldSubEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Hit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Hit::Class_Name()
{
   return "Hit";
}

//______________________________________________________________________________
const char *Hit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Hit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Hit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Hit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventHdr::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventHdr::Class_Name()
{
   return "EventHdr";
}

//______________________________________________________________________________
const char *EventHdr::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventHdr*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventHdr::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventHdr*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventHdr::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventHdr*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventHdr::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventHdr*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Event::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Event::Class_Name()
{
   return "Event";
}

//______________________________________________________________________________
const char *Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Event::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Event*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr HldEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HldEvent::Class_Name()
{
   return "HldEvent";
}

//______________________________________________________________________________
const char *HldEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HldEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HldEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HldEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HldEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HldEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HldEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HldEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Unpacker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Unpacker::Class_Name()
{
   return "Unpacker";
}

//______________________________________________________________________________
const char *Unpacker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Unpacker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Unpacker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Unpacker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Unpacker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Unpacker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Unpacker::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Unpacker*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RpcLookupTable::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RpcLookupTable::Class_Name()
{
   return "RpcLookupTable";
}

//______________________________________________________________________________
const char *RpcLookupTable::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RpcLookupTable*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RpcLookupTable::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RpcLookupTable*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RpcLookupTable::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RpcLookupTable*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RpcLookupTable::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RpcLookupTable*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcCalPar::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcCalPar::Class_Name()
{
   return "TRpcCalPar";
}

//______________________________________________________________________________
const char *TRpcCalPar::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcCalPar*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcCalPar::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcCalPar*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcCalPar::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcCalPar*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcCalPar::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcCalPar*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcRaw::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcRaw::Class_Name()
{
   return "TRpcRaw";
}

//______________________________________________________________________________
const char *TRpcRaw::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcRaw*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcRaw::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcRaw*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcRaw::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcRaw*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcRaw::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcRaw*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcRawF::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcRawF::Class_Name()
{
   return "TRpcRawF";
}

//______________________________________________________________________________
const char *TRpcRawF::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcRawF*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcRawF::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcRawF*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcRawF::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcRawF*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcRawF::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcRawF*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcHit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcHit::Class_Name()
{
   return "TRpcHit";
}

//______________________________________________________________________________
const char *TRpcHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcHit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcHit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcHit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcHit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TActiveCells::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TActiveCells::Class_Name()
{
   return "TActiveCells";
}

//______________________________________________________________________________
const char *TActiveCells::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TActiveCells*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TActiveCells::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TActiveCells*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TActiveCells::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TActiveCells*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TActiveCells::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TActiveCells*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcHitF::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcHitF::Class_Name()
{
   return "TRpcHitF";
}

//______________________________________________________________________________
const char *TRpcHitF::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcHitF*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcHitF::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcHitF*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcHitF::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcHitF*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcHitF::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcHitF*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcSaeta::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcSaeta::Class_Name()
{
   return "TRpcSaeta";
}

//______________________________________________________________________________
const char *TRpcSaeta::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaeta*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcSaeta::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaeta*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcSaeta::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaeta*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcSaeta::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaeta*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TRpcSaetaF::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRpcSaetaF::Class_Name()
{
   return "TRpcSaetaF";
}

//______________________________________________________________________________
const char *TRpcSaetaF::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaetaF*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRpcSaetaF::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaetaF*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRpcSaetaF::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaetaF*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRpcSaetaF::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRpcSaetaF*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TTMatrix::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TTMatrix::Class_Name()
{
   return "TTMatrix";
}

//______________________________________________________________________________
const char *TTMatrix::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTMatrix*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TTMatrix::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTMatrix*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TTMatrix::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTMatrix*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TTMatrix::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTMatrix*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HldSubEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class HldSubEvent.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HldSubEvent(void *p) {
      return  p ? new(p) ::HldSubEvent : new ::HldSubEvent;
   }
   static void *newArray_HldSubEvent(Long_t nElements, void *p) {
      return p ? new(p) ::HldSubEvent[nElements] : new ::HldSubEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_HldSubEvent(void *p) {
      delete ((::HldSubEvent*)p);
   }
   static void deleteArray_HldSubEvent(void *p) {
      delete [] ((::HldSubEvent*)p);
   }
   static void destruct_HldSubEvent(void *p) {
      typedef ::HldSubEvent current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_HldSubEvent(TBuffer &buf, void *obj) {
      ((::HldSubEvent*)obj)->::HldSubEvent::Streamer(buf);
   }
} // end of namespace ROOT for class ::HldSubEvent

//______________________________________________________________________________
void Hit::Streamer(TBuffer &R__b)
{
   // Stream an object of class Hit.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> channel;
      R__b >> TDC;
      R__b >> nHits;
      R__b >> trbNum;
      R__b >> width;
      R__b >> leadTime1;
      R__b >> trailTime1;
      R__b >> leadTime2;
      R__b >> trailTime2;
      R__b >> leadTime3;
      R__b >> trailTime3;
      R__b >> leadTime4;
      R__b >> trailTime4;
      R__b >> spikesCtr;
      R__b.CheckByteCount(R__s, R__c, Hit::IsA());
   } else {
      R__c = R__b.WriteVersion(Hit::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << channel;
      R__b << TDC;
      R__b << nHits;
      R__b << trbNum;
      R__b << width;
      R__b << leadTime1;
      R__b << trailTime1;
      R__b << leadTime2;
      R__b << trailTime2;
      R__b << leadTime3;
      R__b << trailTime3;
      R__b << leadTime4;
      R__b << trailTime4;
      R__b << spikesCtr;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Hit(void *p) {
      return  p ? new(p) ::Hit : new ::Hit;
   }
   static void *newArray_Hit(Long_t nElements, void *p) {
      return p ? new(p) ::Hit[nElements] : new ::Hit[nElements];
   }
   // Wrapper around operator delete
   static void delete_Hit(void *p) {
      delete ((::Hit*)p);
   }
   static void deleteArray_Hit(void *p) {
      delete [] ((::Hit*)p);
   }
   static void destruct_Hit(void *p) {
      typedef ::Hit current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_Hit(TBuffer &buf, void *obj) {
      ((::Hit*)obj)->::Hit::Streamer(buf);
   }
} // end of namespace ROOT for class ::Hit

//______________________________________________________________________________
void EventHdr::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventHdr.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> size;
      R__b >> decoding;
      R__b >> id;
      R__b >> seqNr;
      R__b >> date;
      R__b >> time;
      R__b >> year;
      R__b >> month;
      R__b >> day;
      R__b >> hour;
      R__b >> minute;
      R__b >> second;
      R__b >> pad;
      R__b >> dataSize;
      R__b >> paddedSize;
      R__b.CheckByteCount(R__s, R__c, EventHdr::IsA());
   } else {
      R__c = R__b.WriteVersion(EventHdr::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << size;
      R__b << decoding;
      R__b << id;
      R__b << seqNr;
      R__b << date;
      R__b << time;
      R__b << year;
      R__b << month;
      R__b << day;
      R__b << hour;
      R__b << minute;
      R__b << second;
      R__b << pad;
      R__b << dataSize;
      R__b << paddedSize;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EventHdr(void *p) {
      return  p ? new(p) ::EventHdr : new ::EventHdr;
   }
   static void *newArray_EventHdr(Long_t nElements, void *p) {
      return p ? new(p) ::EventHdr[nElements] : new ::EventHdr[nElements];
   }
   // Wrapper around operator delete
   static void delete_EventHdr(void *p) {
      delete ((::EventHdr*)p);
   }
   static void deleteArray_EventHdr(void *p) {
      delete [] ((::EventHdr*)p);
   }
   static void destruct_EventHdr(void *p) {
      typedef ::EventHdr current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_EventHdr(TBuffer &buf, void *obj) {
      ((::EventHdr*)obj)->::EventHdr::Streamer(buf);
   }
} // end of namespace ROOT for class ::EventHdr

//______________________________________________________________________________
void Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class Event.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      EvtHdr.Streamer(R__b);
      R__b >> const_cast< Int_t &>( kMaxMult );
      R__b >> const_cast< Int_t &>( kMaxChannelNr );
      R__b >> subEvtId;
      R__b >> errors_per_event;
      R__b >> referenceChannel;
      R__b >> referenceTime;
      R__b >> totalNHits;
      R__b >> multH1;
      R__b >> multH2;
      R__b >> multH3;
      R__b >> chargeH1;
      R__b >> chargeH2;
      R__b >> chargeH3;
      R__b >> multT;
      R__b >> multT3;
      R__b >> sync;
      R__b >> fEvAl;
      R__b >> fEvBe;
      R__b >> fEvGa;
      R__b >> fEvAl3Planes;
      R__b >> fEvBe3Planes;
      R__b >> fEvGa3Planes;
      R__b.CheckByteCount(R__s, R__c, Event::IsA());
   } else {
      R__c = R__b.WriteVersion(Event::IsA(), kTRUE);
      TObject::Streamer(R__b);
      EvtHdr.Streamer(R__b);
      R__b << const_cast< Int_t &>( kMaxMult );
      R__b << const_cast< Int_t &>( kMaxChannelNr );
      R__b << subEvtId;
      R__b << errors_per_event;
      R__b << referenceChannel;
      R__b << referenceTime;
      R__b << totalNHits;
      R__b << multH1;
      R__b << multH2;
      R__b << multH3;
      R__b << chargeH1;
      R__b << chargeH2;
      R__b << chargeH3;
      R__b << multT;
      R__b << multT3;
      R__b << sync;
      R__b << fEvAl;
      R__b << fEvBe;
      R__b << fEvGa;
      R__b << fEvAl3Planes;
      R__b << fEvBe3Planes;
      R__b << fEvGa3Planes;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Event(void *p) {
      return  p ? new(p) ::Event : new ::Event;
   }
   static void *newArray_Event(Long_t nElements, void *p) {
      return p ? new(p) ::Event[nElements] : new ::Event[nElements];
   }
   // Wrapper around operator delete
   static void delete_Event(void *p) {
      delete ((::Event*)p);
   }
   static void deleteArray_Event(void *p) {
      delete [] ((::Event*)p);
   }
   static void destruct_Event(void *p) {
      typedef ::Event current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_Event(TBuffer &buf, void *obj) {
      ((::Event*)obj)->::Event::Streamer(buf);
   }
} // end of namespace ROOT for class ::Event

//______________________________________________________________________________
void HldEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class HldEvent.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HldEvent(void *p) {
      return  p ? new(p) ::HldEvent : new ::HldEvent;
   }
   static void *newArray_HldEvent(Long_t nElements, void *p) {
      return p ? new(p) ::HldEvent[nElements] : new ::HldEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_HldEvent(void *p) {
      delete ((::HldEvent*)p);
   }
   static void deleteArray_HldEvent(void *p) {
      delete [] ((::HldEvent*)p);
   }
   static void destruct_HldEvent(void *p) {
      typedef ::HldEvent current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_HldEvent(TBuffer &buf, void *obj) {
      ((::HldEvent*)obj)->::HldEvent::Streamer(buf);
   }
} // end of namespace ROOT for class ::HldEvent

//______________________________________________________________________________
void Unpacker::Streamer(TBuffer &R__b)
{
   // Stream an object of class Unpacker.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> pEvent;
      R__b >> EventNr;
      R__b >> EventLimit;
      R__b >> subEvtId;
      R__b >> pRootFile;
      { TString R__str; R__str.Streamer(R__b); inputFile = R__str.Data(); }
      { TString R__str; R__str.Streamer(R__b); outputFile = R__str.Data(); }
      R__b >> fpga_code;
      R__b >> refCh;
      R__b.CheckByteCount(R__s, R__c, Unpacker::IsA());
   } else {
      R__c = R__b.WriteVersion(Unpacker::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << pEvent;
      R__b << EventNr;
      R__b << EventLimit;
      R__b << subEvtId;
      R__b << pRootFile;
      { TString R__str = inputFile.c_str(); R__str.Streamer(R__b);}
      { TString R__str = outputFile.c_str(); R__str.Streamer(R__b);}
      R__b << fpga_code;
      R__b << refCh;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Unpacker(void *p) {
      return  p ? new(p) ::Unpacker : new ::Unpacker;
   }
   static void *newArray_Unpacker(Long_t nElements, void *p) {
      return p ? new(p) ::Unpacker[nElements] : new ::Unpacker[nElements];
   }
   // Wrapper around operator delete
   static void delete_Unpacker(void *p) {
      delete ((::Unpacker*)p);
   }
   static void deleteArray_Unpacker(void *p) {
      delete [] ((::Unpacker*)p);
   }
   static void destruct_Unpacker(void *p) {
      typedef ::Unpacker current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_Unpacker(TBuffer &buf, void *obj) {
      ((::Unpacker*)obj)->::Unpacker::Streamer(buf);
   }
} // end of namespace ROOT for class ::Unpacker

//______________________________________________________________________________
void RpcLookupTable::Streamer(TBuffer &R__b)
{
   // Stream an object of class RpcLookupTable.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RpcLookupTable(void *p) {
      return  p ? new(p) ::RpcLookupTable : new ::RpcLookupTable;
   }
   static void *newArray_RpcLookupTable(Long_t nElements, void *p) {
      return p ? new(p) ::RpcLookupTable[nElements] : new ::RpcLookupTable[nElements];
   }
   // Wrapper around operator delete
   static void delete_RpcLookupTable(void *p) {
      delete ((::RpcLookupTable*)p);
   }
   static void deleteArray_RpcLookupTable(void *p) {
      delete [] ((::RpcLookupTable*)p);
   }
   static void destruct_RpcLookupTable(void *p) {
      typedef ::RpcLookupTable current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_RpcLookupTable(TBuffer &buf, void *obj) {
      ((::RpcLookupTable*)obj)->::RpcLookupTable::Streamer(buf);
   }
} // end of namespace ROOT for class ::RpcLookupTable

//______________________________________________________________________________
void TRpcCalPar::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcCalPar.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcCalPar(void *p) {
      return  p ? new(p) ::TRpcCalPar : new ::TRpcCalPar;
   }
   static void *newArray_TRpcCalPar(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcCalPar[nElements] : new ::TRpcCalPar[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcCalPar(void *p) {
      delete ((::TRpcCalPar*)p);
   }
   static void deleteArray_TRpcCalPar(void *p) {
      delete [] ((::TRpcCalPar*)p);
   }
   static void destruct_TRpcCalPar(void *p) {
      typedef ::TRpcCalPar current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcCalPar(TBuffer &buf, void *obj) {
      ((::TRpcCalPar*)obj)->::TRpcCalPar::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcCalPar

//______________________________________________________________________________
void TRpcRaw::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcRaw.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fTrbnum;
      R__b >> fCell;
      R__b >> fCol;
      R__b >> fRow;
      R__b >> fX;
      R__b >> fY;
      R__b >> fZ;
      R__b >> fTime;
      R__b >> fCharge;
      R__b.CheckByteCount(R__s, R__c, TRpcRaw::IsA());
   } else {
      R__c = R__b.WriteVersion(TRpcRaw::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fTrbnum;
      R__b << fCell;
      R__b << fCol;
      R__b << fRow;
      R__b << fX;
      R__b << fY;
      R__b << fZ;
      R__b << fTime;
      R__b << fCharge;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcRaw(void *p) {
      return  p ? new(p) ::TRpcRaw : new ::TRpcRaw;
   }
   static void *newArray_TRpcRaw(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcRaw[nElements] : new ::TRpcRaw[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcRaw(void *p) {
      delete ((::TRpcRaw*)p);
   }
   static void deleteArray_TRpcRaw(void *p) {
      delete [] ((::TRpcRaw*)p);
   }
   static void destruct_TRpcRaw(void *p) {
      typedef ::TRpcRaw current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcRaw(TBuffer &buf, void *obj) {
      ((::TRpcRaw*)obj)->::TRpcRaw::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcRaw

//______________________________________________________________________________
void TRpcRawF::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcRawF.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcRawF(void *p) {
      return  p ? new(p) ::TRpcRawF : new ::TRpcRawF;
   }
   static void *newArray_TRpcRawF(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcRawF[nElements] : new ::TRpcRawF[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcRawF(void *p) {
      delete ((::TRpcRawF*)p);
   }
   static void deleteArray_TRpcRawF(void *p) {
      delete [] ((::TRpcRawF*)p);
   }
   static void destruct_TRpcRawF(void *p) {
      typedef ::TRpcRawF current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcRawF(TBuffer &buf, void *obj) {
      ((::TRpcRawF*)obj)->::TRpcRawF::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcRawF

//______________________________________________________________________________
void TRpcHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcHit.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fTrbnum;
      R__b >> fCell;
      R__b >> fCol;
      R__b >> fRow;
      R__b >> fX;
      R__b >> fY;
      R__b >> fZ;
      R__b >> fTime;
      R__b >> fCharge;
      R__b.CheckByteCount(R__s, R__c, TRpcHit::IsA());
   } else {
      R__c = R__b.WriteVersion(TRpcHit::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fTrbnum;
      R__b << fCell;
      R__b << fCol;
      R__b << fRow;
      R__b << fX;
      R__b << fY;
      R__b << fZ;
      R__b << fTime;
      R__b << fCharge;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcHit(void *p) {
      return  p ? new(p) ::TRpcHit : new ::TRpcHit;
   }
   static void *newArray_TRpcHit(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcHit[nElements] : new ::TRpcHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcHit(void *p) {
      delete ((::TRpcHit*)p);
   }
   static void deleteArray_TRpcHit(void *p) {
      delete [] ((::TRpcHit*)p);
   }
   static void destruct_TRpcHit(void *p) {
      typedef ::TRpcHit current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcHit(TBuffer &buf, void *obj) {
      ((::TRpcHit*)obj)->::TRpcHit::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcHit

//______________________________________________________________________________
void TActiveCells::Streamer(TBuffer &R__b)
{
   // Stream an object of class TActiveCells.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TActiveCells(void *p) {
      return  p ? new(p) ::TActiveCells : new ::TActiveCells;
   }
   static void *newArray_TActiveCells(Long_t nElements, void *p) {
      return p ? new(p) ::TActiveCells[nElements] : new ::TActiveCells[nElements];
   }
   // Wrapper around operator delete
   static void delete_TActiveCells(void *p) {
      delete ((::TActiveCells*)p);
   }
   static void deleteArray_TActiveCells(void *p) {
      delete [] ((::TActiveCells*)p);
   }
   static void destruct_TActiveCells(void *p) {
      typedef ::TActiveCells current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TActiveCells(TBuffer &buf, void *obj) {
      ((::TActiveCells*)obj)->::TActiveCells::Streamer(buf);
   }
} // end of namespace ROOT for class ::TActiveCells

//______________________________________________________________________________
void TRpcHitF::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcHitF.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcHitF(void *p) {
      return  p ? new(p) ::TRpcHitF : new ::TRpcHitF;
   }
   static void *newArray_TRpcHitF(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcHitF[nElements] : new ::TRpcHitF[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcHitF(void *p) {
      delete ((::TRpcHitF*)p);
   }
   static void deleteArray_TRpcHitF(void *p) {
      delete [] ((::TRpcHitF*)p);
   }
   static void destruct_TRpcHitF(void *p) {
      typedef ::TRpcHitF current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcHitF(TBuffer &buf, void *obj) {
      ((::TRpcHitF*)obj)->::TRpcHitF::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcHitF

//______________________________________________________________________________
void TRpcSaeta::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcSaeta.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fX;
      R__b >> fXP;
      R__b >> fY;
      R__b >> fYP;
      R__b >> fZ;
      R__b >> fTime;
      R__b >> fSlow;
      R__b >> fAl;
      R__b >> fBe;
      R__b >> fGa;
      R__b >> fSaN;
      R__b >> find0;
      R__b >> find1;
      R__b >> find2;
      R__b >> fChi2;
      R__b.CheckByteCount(R__s, R__c, TRpcSaeta::IsA());
   } else {
      R__c = R__b.WriteVersion(TRpcSaeta::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fX;
      R__b << fXP;
      R__b << fY;
      R__b << fYP;
      R__b << fZ;
      R__b << fTime;
      R__b << fSlow;
      R__b << fAl;
      R__b << fBe;
      R__b << fGa;
      R__b << fSaN;
      R__b << find0;
      R__b << find1;
      R__b << find2;
      R__b << fChi2;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcSaeta(void *p) {
      return  p ? new(p) ::TRpcSaeta : new ::TRpcSaeta;
   }
   static void *newArray_TRpcSaeta(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcSaeta[nElements] : new ::TRpcSaeta[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcSaeta(void *p) {
      delete ((::TRpcSaeta*)p);
   }
   static void deleteArray_TRpcSaeta(void *p) {
      delete [] ((::TRpcSaeta*)p);
   }
   static void destruct_TRpcSaeta(void *p) {
      typedef ::TRpcSaeta current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcSaeta(TBuffer &buf, void *obj) {
      ((::TRpcSaeta*)obj)->::TRpcSaeta::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcSaeta

//______________________________________________________________________________
void TRpcSaetaF::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRpcSaetaF.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      fRpcHitHits->Streamer(R__b);
      fRpcHitCorr->Streamer(R__b);
      fRpcSaeta2Planes->Streamer(R__b);
      fRpcSaeta3Planes->Streamer(R__b);
      R__b >> totalNHits;
      R__b >> totalNHits2Planes;
      R__b >> totalNHits3Planes;
      R__b >> totalNHitsCorr;
      R__b.CheckByteCount(R__s, R__c, TRpcSaetaF::IsA());
   } else {
      R__c = R__b.WriteVersion(TRpcSaetaF::IsA(), kTRUE);
      TObject::Streamer(R__b);
      fRpcHitHits->Streamer(R__b);
      fRpcHitCorr->Streamer(R__b);
      fRpcSaeta2Planes->Streamer(R__b);
      fRpcSaeta3Planes->Streamer(R__b);
      R__b << totalNHits;
      R__b << totalNHits2Planes;
      R__b << totalNHits3Planes;
      R__b << totalNHitsCorr;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRpcSaetaF(void *p) {
      return  p ? new(p) ::TRpcSaetaF : new ::TRpcSaetaF;
   }
   static void *newArray_TRpcSaetaF(Long_t nElements, void *p) {
      return p ? new(p) ::TRpcSaetaF[nElements] : new ::TRpcSaetaF[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRpcSaetaF(void *p) {
      delete ((::TRpcSaetaF*)p);
   }
   static void deleteArray_TRpcSaetaF(void *p) {
      delete [] ((::TRpcSaetaF*)p);
   }
   static void destruct_TRpcSaetaF(void *p) {
      typedef ::TRpcSaetaF current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRpcSaetaF(TBuffer &buf, void *obj) {
      ((::TRpcSaetaF*)obj)->::TRpcSaetaF::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRpcSaetaF

//______________________________________________________________________________
void TTMatrix::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTMatrix.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      R__b >> fX1;
      R__b >> fY1;
      R__b >> fT1;
      R__b >> fZ1;
      R__b >> fX2;
      R__b >> fY2;
      R__b >> fT2;
      R__b >> fZ2;
      R__b >> fwx;
      R__b >> fwy;
      R__b >> fwz;
      R__b.CheckByteCount(R__s, R__c, TTMatrix::IsA());
   } else {
      R__c = R__b.WriteVersion(TTMatrix::IsA(), kTRUE);
      TObject::Streamer(R__b);
      R__b << fX1;
      R__b << fY1;
      R__b << fT1;
      R__b << fZ1;
      R__b << fX2;
      R__b << fY2;
      R__b << fT2;
      R__b << fZ2;
      R__b << fwx;
      R__b << fwy;
      R__b << fwz;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTMatrix(void *p) {
      return  p ? new(p) ::TTMatrix : new ::TTMatrix;
   }
   static void *newArray_TTMatrix(Long_t nElements, void *p) {
      return p ? new(p) ::TTMatrix[nElements] : new ::TTMatrix[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTMatrix(void *p) {
      delete ((::TTMatrix*)p);
   }
   static void deleteArray_TTMatrix(void *p) {
      delete [] ((::TTMatrix*)p);
   }
   static void destruct_TTMatrix(void *p) {
      typedef ::TTMatrix current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TTMatrix(TBuffer &buf, void *obj) {
      ((::TTMatrix*)obj)->::TTMatrix::Streamer(buf);
   }
} // end of namespace ROOT for class ::TTMatrix

namespace {
  void TriggerDictionaryInitialization_tmydict_Impl() {
    static const char* headers[] = {
"tunpacker.h",
"thldevent.h",
"thldsubevent.h",
"tevent.h",
"teventhdr.h",
"trpclookuptable.h",
"thit.h",
"trpccalpar.h",
"trpcraw.h",
"trpcrawf.h",
"trpchit.h",
"trpchitf.h",
"trpcsaeta.h",
"trpcsaetaf.h",
"tactivecells.h",
"ttmatrix.h",
0
    };
    static const char* includePaths[] = {
"/home/mcruces/Cern_Root/root-6.20.04/root-install/include/",
"/home/mcruces/Documents/GitHub/TRAGALDABAS-fantastic-Cpp/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "tmydict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$thldsubevent.h")))  __attribute__((annotate("$clingAutoload$tunpacker.h")))  HldSubEvent;
class __attribute__((annotate("$clingAutoload$thit.h")))  __attribute__((annotate("$clingAutoload$tunpacker.h")))  Hit;
class __attribute__((annotate("$clingAutoload$teventhdr.h")))  __attribute__((annotate("$clingAutoload$tunpacker.h")))  EventHdr;
class __attribute__((annotate("$clingAutoload$tevent.h")))  __attribute__((annotate("$clingAutoload$tunpacker.h")))  Event;
class __attribute__((annotate("$clingAutoload$thldevent.h")))  __attribute__((annotate("$clingAutoload$tunpacker.h")))  HldEvent;
class __attribute__((annotate("$clingAutoload$tunpacker.h")))  Unpacker;
class __attribute__((annotate("$clingAutoload$trpclookuptable.h")))  RpcLookupTable;
class __attribute__((annotate("$clingAutoload$trpccalpar.h")))  TRpcCalPar;
class __attribute__((annotate("$clingAutoload$trpcraw.h")))  TRpcRaw;
class __attribute__((annotate("$clingAutoload$trpcrawf.h")))  TRpcRawF;
class __attribute__((annotate("$clingAutoload$trpchit.h")))  TRpcHit;
class __attribute__((annotate("$clingAutoload$tactivecells.h")))  __attribute__((annotate("$clingAutoload$trpchitf.h")))  TActiveCells;
class __attribute__((annotate("$clingAutoload$trpchitf.h")))  TRpcHitF;
class __attribute__((annotate("$clingAutoload$trpcsaeta.h")))  TRpcSaeta;
class __attribute__((annotate("$clingAutoload$trpcsaetaf.h")))  TRpcSaetaF;
class __attribute__((annotate("$clingAutoload$ttmatrix.h")))  TTMatrix;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "tmydict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "tunpacker.h"
#include "thldevent.h"
#include "thldsubevent.h"
#include "tevent.h"
#include "teventhdr.h"
#include "trpclookuptable.h"
#include "thit.h"
#include "trpccalpar.h"
#include "trpcraw.h"
#include "trpcrawf.h"
#include "trpchit.h"
#include "trpchitf.h"
#include "trpcsaeta.h"
#include "trpcsaetaf.h"
#include "tactivecells.h"
#include "ttmatrix.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Event", payloadCode, "@",
"EventHdr", payloadCode, "@",
"Hit", payloadCode, "@",
"HldEvent", payloadCode, "@",
"HldSubEvent", payloadCode, "@",
"RpcLookupTable", payloadCode, "@",
"TActiveCells", payloadCode, "@",
"TRpcCalPar", payloadCode, "@",
"TRpcHit", payloadCode, "@",
"TRpcHitF", payloadCode, "@",
"TRpcRaw", payloadCode, "@",
"TRpcRawF", payloadCode, "@",
"TRpcSaeta", payloadCode, "@",
"TRpcSaetaF", payloadCode, "@",
"TTMatrix", payloadCode, "@",
"Unpacker", payloadCode, "@",
"gEvent", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("tmydict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_tmydict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_tmydict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_tmydict() {
  TriggerDictionaryInitialization_tmydict_Impl();
}
