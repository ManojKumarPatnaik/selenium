/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-2.0-xr-w32-bld/build/dom/interfaces/threads/nsIDOMWorkers.idl
 */

#ifndef __gen_nsIDOMWorkers_h__
#define __gen_nsIDOMWorkers_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIWorkerMessagePort */
#define NS_IWORKERMESSAGEPORT_IID_STR "ab3725b8-3fca-40cc-a42c-92fb154ef01d"

#define NS_IWORKERMESSAGEPORT_IID \
  {0xab3725b8, 0x3fca, 0x40cc, \
    { 0xa4, 0x2c, 0x92, 0xfb, 0x15, 0x4e, 0xf0, 0x1d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerMessagePort : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERMESSAGEPORT_IID)

  /* void postMessage (); */
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerMessagePort, NS_IWORKERMESSAGEPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERMESSAGEPORT \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERMESSAGEPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) { return _to PostMessage(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERMESSAGEPORT(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessage(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerMessagePort : public nsIWorkerMessagePort
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERMESSAGEPORT

  nsWorkerMessagePort();

private:
  ~nsWorkerMessagePort();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerMessagePort, nsIWorkerMessagePort)

nsWorkerMessagePort::nsWorkerMessagePort()
{
  /* member initializers and constructor code */
}

nsWorkerMessagePort::~nsWorkerMessagePort()
{
  /* destructor code */
}

/* void postMessage (); */
NS_IMETHODIMP nsWorkerMessagePort::PostMessage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerMessageEvent */
#define NS_IWORKERMESSAGEEVENT_IID_STR "508f2d49-e9a0-4fe8-bd33-321820173b4a"

#define NS_IWORKERMESSAGEEVENT_IID \
  {0x508f2d49, 0xe9a0, 0x4fe8, \
    { 0xbd, 0x33, 0x32, 0x18, 0x20, 0x17, 0x3b, 0x4a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerMessageEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERMESSAGEEVENT_IID)

  /* readonly attribute DOMString data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) = 0;

  /* readonly attribute DOMString origin; */
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin) = 0;

  /* readonly attribute nsISupports source; */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource) = 0;

  /* void initMessageEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in DOMString aDataArg, in DOMString aOriginArg, in nsISupports aSourceArg); */
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aDataArg, const nsAString & aOriginArg, nsISupports *aSourceArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerMessageEvent, NS_IWORKERMESSAGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERMESSAGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData); \
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin); \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource); \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aDataArg, const nsAString & aOriginArg, nsISupports *aSourceArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERMESSAGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return _to GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin) { return _to GetOrigin(aOrigin); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource) { return _to GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aDataArg, const nsAString & aOriginArg, nsISupports *aSourceArg) { return _to InitMessageEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aDataArg, aOriginArg, aSourceArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERMESSAGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrigin(nsAString & aOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsISupports **aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD InitMessageEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aDataArg, const nsAString & aOriginArg, nsISupports *aSourceArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMessageEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aDataArg, aOriginArg, aSourceArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerMessageEvent : public nsIWorkerMessageEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERMESSAGEEVENT

  nsWorkerMessageEvent();

private:
  ~nsWorkerMessageEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerMessageEvent, nsIWorkerMessageEvent)

nsWorkerMessageEvent::nsWorkerMessageEvent()
{
  /* member initializers and constructor code */
}

nsWorkerMessageEvent::~nsWorkerMessageEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString data; */
NS_IMETHODIMP nsWorkerMessageEvent::GetData(nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString origin; */
NS_IMETHODIMP nsWorkerMessageEvent::GetOrigin(nsAString & aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports source; */
NS_IMETHODIMP nsWorkerMessageEvent::GetSource(nsISupports **aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMessageEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in DOMString aDataArg, in DOMString aOriginArg, in nsISupports aSourceArg); */
NS_IMETHODIMP nsWorkerMessageEvent::InitMessageEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aDataArg, const nsAString & aOriginArg, nsISupports *aSourceArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerErrorEvent */
#define NS_IWORKERERROREVENT_IID_STR "73d82c1d-05de-49c9-a23b-7121ff09a67a"

#define NS_IWORKERERROREVENT_IID \
  {0x73d82c1d, 0x05de, 0x49c9, \
    { 0xa2, 0x3b, 0x71, 0x21, 0xff, 0x09, 0xa6, 0x7a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerErrorEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERERROREVENT_IID)

  /* readonly attribute DOMString message; */
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

  /* readonly attribute DOMString filename; */
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename) = 0;

  /* readonly attribute unsigned long lineno; */
  NS_SCRIPTABLE NS_IMETHOD GetLineno(PRUint32 *aLineno) = 0;

  /* void initErrorEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in DOMString aMessageArg, in DOMString aFilenameArg, in unsigned long aLinenoArg); */
  NS_SCRIPTABLE NS_IMETHOD InitErrorEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aMessageArg, const nsAString & aFilenameArg, PRUint32 aLinenoArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerErrorEvent, NS_IWORKERERROREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERERROREVENT \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage); \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename); \
  NS_SCRIPTABLE NS_IMETHOD GetLineno(PRUint32 *aLineno); \
  NS_SCRIPTABLE NS_IMETHOD InitErrorEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aMessageArg, const nsAString & aFilenameArg, PRUint32 aLinenoArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERERROREVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename) { return _to GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineno(PRUint32 *aLineno) { return _to GetLineno(aLineno); } \
  NS_SCRIPTABLE NS_IMETHOD InitErrorEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aMessageArg, const nsAString & aFilenameArg, PRUint32 aLinenoArg) { return _to InitErrorEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aMessageArg, aFilenameArg, aLinenoArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERERROREVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetLineno(PRUint32 *aLineno) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineno(aLineno); } \
  NS_SCRIPTABLE NS_IMETHOD InitErrorEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aMessageArg, const nsAString & aFilenameArg, PRUint32 aLinenoArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitErrorEvent(aTypeArg, aCanBubbleArg, aCancelableArg, aMessageArg, aFilenameArg, aLinenoArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerErrorEvent : public nsIWorkerErrorEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERERROREVENT

  nsWorkerErrorEvent();

private:
  ~nsWorkerErrorEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerErrorEvent, nsIWorkerErrorEvent)

nsWorkerErrorEvent::nsWorkerErrorEvent()
{
  /* member initializers and constructor code */
}

nsWorkerErrorEvent::~nsWorkerErrorEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString message; */
NS_IMETHODIMP nsWorkerErrorEvent::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString filename; */
NS_IMETHODIMP nsWorkerErrorEvent::GetFilename(nsAString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long lineno; */
NS_IMETHODIMP nsWorkerErrorEvent::GetLineno(PRUint32 *aLineno)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initErrorEvent (in DOMString aTypeArg, in boolean aCanBubbleArg, in boolean aCancelableArg, in DOMString aMessageArg, in DOMString aFilenameArg, in unsigned long aLinenoArg); */
NS_IMETHODIMP nsWorkerErrorEvent::InitErrorEvent(const nsAString & aTypeArg, PRBool aCanBubbleArg, PRBool aCancelableArg, const nsAString & aMessageArg, const nsAString & aFilenameArg, PRUint32 aLinenoArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerLocation */
#define NS_IWORKERLOCATION_IID_STR "17a005c3-4f2f-4bb6-b169-c181fa6873de"

#define NS_IWORKERLOCATION_IID \
  {0x17a005c3, 0x4f2f, 0x4bb6, \
    { 0xb1, 0x69, 0xc1, 0x81, 0xfa, 0x68, 0x73, 0xde }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerLocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERLOCATION_IID)

  /* readonly attribute AUTF8String href; */
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsACString & aHref) = 0;

  /* readonly attribute AUTF8String protocol; */
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsACString & aProtocol) = 0;

  /* readonly attribute AUTF8String host; */
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) = 0;

  /* readonly attribute AUTF8String hostname; */
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsACString & aHostname) = 0;

  /* readonly attribute AUTF8String port; */
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsACString & aPort) = 0;

  /* readonly attribute AUTF8String pathname; */
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsACString & aPathname) = 0;

  /* readonly attribute AUTF8String search; */
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsACString & aSearch) = 0;

  /* readonly attribute AUTF8String hash; */
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsACString & aHash) = 0;

  /* AUTF8String toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerLocation, NS_IWORKERLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERLOCATION \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsACString & aHref); \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsACString & aProtocol); \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost); \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsACString & aHostname); \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsACString & aPort); \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsACString & aPathname); \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsACString & aSearch); \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsACString & aHash); \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsACString & aHref) { return _to GetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsACString & aProtocol) { return _to GetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) { return _to GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsACString & aHostname) { return _to GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsACString & aPort) { return _to GetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsACString & aPathname) { return _to GetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsACString & aSearch) { return _to GetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsACString & aHash) { return _to GetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHref(nsACString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_SCRIPTABLE NS_IMETHOD GetProtocol(nsACString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocol(aProtocol); } \
  NS_SCRIPTABLE NS_IMETHOD GetHost(nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetHostname(nsACString & aHostname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostname(aHostname); } \
  NS_SCRIPTABLE NS_IMETHOD GetPort(nsACString & aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathname(nsACString & aPathname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathname(aPathname); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearch(nsACString & aSearch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearch(aSearch); } \
  NS_SCRIPTABLE NS_IMETHOD GetHash(nsACString & aHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHash(aHash); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerLocation : public nsIWorkerLocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERLOCATION

  nsWorkerLocation();

private:
  ~nsWorkerLocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerLocation, nsIWorkerLocation)

nsWorkerLocation::nsWorkerLocation()
{
  /* member initializers and constructor code */
}

nsWorkerLocation::~nsWorkerLocation()
{
  /* destructor code */
}

/* readonly attribute AUTF8String href; */
NS_IMETHODIMP nsWorkerLocation::GetHref(nsACString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String protocol; */
NS_IMETHODIMP nsWorkerLocation::GetProtocol(nsACString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String host; */
NS_IMETHODIMP nsWorkerLocation::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hostname; */
NS_IMETHODIMP nsWorkerLocation::GetHostname(nsACString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String port; */
NS_IMETHODIMP nsWorkerLocation::GetPort(nsACString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String pathname; */
NS_IMETHODIMP nsWorkerLocation::GetPathname(nsACString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String search; */
NS_IMETHODIMP nsWorkerLocation::GetSearch(nsACString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String hash; */
NS_IMETHODIMP nsWorkerLocation::GetHash(nsACString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsWorkerLocation::ToString(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerNavigator */
#define NS_IWORKERNAVIGATOR_IID_STR "74fb665a-e477-4ce2-b3c6-c58b1b28b6c3"

#define NS_IWORKERNAVIGATOR_IID \
  {0x74fb665a, 0xe477, 0x4ce2, \
    { 0xb3, 0xc6, 0xc5, 0x8b, 0x1b, 0x28, 0xb6, 0xc3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerNavigator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERNAVIGATOR_IID)

  /* readonly attribute DOMString appName; */
  NS_SCRIPTABLE NS_IMETHOD GetAppName(nsAString & aAppName) = 0;

  /* readonly attribute DOMString appVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetAppVersion(nsAString & aAppVersion) = 0;

  /* readonly attribute DOMString platform; */
  NS_SCRIPTABLE NS_IMETHOD GetPlatform(nsAString & aPlatform) = 0;

  /* readonly attribute DOMString userAgent; */
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(nsAString & aUserAgent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerNavigator, NS_IWORKERNAVIGATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERNAVIGATOR \
  NS_SCRIPTABLE NS_IMETHOD GetAppName(nsAString & aAppName); \
  NS_SCRIPTABLE NS_IMETHOD GetAppVersion(nsAString & aAppVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetPlatform(nsAString & aPlatform); \
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(nsAString & aUserAgent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERNAVIGATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAppName(nsAString & aAppName) { return _to GetAppName(aAppName); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppVersion(nsAString & aAppVersion) { return _to GetAppVersion(aAppVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatform(nsAString & aPlatform) { return _to GetPlatform(aPlatform); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(nsAString & aUserAgent) { return _to GetUserAgent(aUserAgent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERNAVIGATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAppName(nsAString & aAppName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppName(aAppName); } \
  NS_SCRIPTABLE NS_IMETHOD GetAppVersion(nsAString & aAppVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppVersion(aAppVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetPlatform(nsAString & aPlatform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatform(aPlatform); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserAgent(nsAString & aUserAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserAgent(aUserAgent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerNavigator : public nsIWorkerNavigator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERNAVIGATOR

  nsWorkerNavigator();

private:
  ~nsWorkerNavigator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerNavigator, nsIWorkerNavigator)

nsWorkerNavigator::nsWorkerNavigator()
{
  /* member initializers and constructor code */
}

nsWorkerNavigator::~nsWorkerNavigator()
{
  /* destructor code */
}

/* readonly attribute DOMString appName; */
NS_IMETHODIMP nsWorkerNavigator::GetAppName(nsAString & aAppName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appVersion; */
NS_IMETHODIMP nsWorkerNavigator::GetAppVersion(nsAString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString platform; */
NS_IMETHODIMP nsWorkerNavigator::GetPlatform(nsAString & aPlatform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString userAgent; */
NS_IMETHODIMP nsWorkerNavigator::GetUserAgent(nsAString & aUserAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerGlobalScope */
#define NS_IWORKERGLOBALSCOPE_IID_STR "c111e7d3-8044-4458-aa7b-637696ffb841"

#define NS_IWORKERGLOBALSCOPE_IID \
  {0xc111e7d3, 0x8044, 0x4458, \
    { 0xaa, 0x7b, 0x63, 0x76, 0x96, 0xff, 0xb8, 0x41 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerGlobalScope : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERGLOBALSCOPE_IID)

  /* readonly attribute nsIWorkerGlobalScope self; */
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIWorkerGlobalScope **aSelf) = 0;

  /* readonly attribute nsIWorkerNavigator navigator; */
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIWorkerNavigator **aNavigator) = 0;

  /* readonly attribute nsIWorkerLocation location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIWorkerLocation **aLocation) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerGlobalScope, NS_IWORKERGLOBALSCOPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERGLOBALSCOPE \
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIWorkerGlobalScope **aSelf); \
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIWorkerNavigator **aNavigator); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIWorkerLocation **aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERGLOBALSCOPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIWorkerGlobalScope **aSelf) { return _to GetSelf(aSelf); } \
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIWorkerNavigator **aNavigator) { return _to GetNavigator(aNavigator); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIWorkerLocation **aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return _to SetOnerror(aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERGLOBALSCOPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelf(nsIWorkerGlobalScope **aSelf) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelf(aSelf); } \
  NS_SCRIPTABLE NS_IMETHOD GetNavigator(nsIWorkerNavigator **aNavigator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNavigator(aNavigator); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIWorkerLocation **aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerGlobalScope : public nsIWorkerGlobalScope
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERGLOBALSCOPE

  nsWorkerGlobalScope();

private:
  ~nsWorkerGlobalScope();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerGlobalScope, nsIWorkerGlobalScope)

nsWorkerGlobalScope::nsWorkerGlobalScope()
{
  /* member initializers and constructor code */
}

nsWorkerGlobalScope::~nsWorkerGlobalScope()
{
  /* destructor code */
}

/* readonly attribute nsIWorkerGlobalScope self; */
NS_IMETHODIMP nsWorkerGlobalScope::GetSelf(nsIWorkerGlobalScope **aSelf)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIWorkerNavigator navigator; */
NS_IMETHODIMP nsWorkerGlobalScope::GetNavigator(nsIWorkerNavigator **aNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIWorkerLocation location; */
NS_IMETHODIMP nsWorkerGlobalScope::GetLocation(nsIWorkerLocation **aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsWorkerGlobalScope::GetOnerror(nsIDOMEventListener **aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWorkerGlobalScope::SetOnerror(nsIDOMEventListener *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerScope */
#define NS_IWORKERSCOPE_IID_STR "5c55ea4b-e4ac-4ceb-bfeb-46bd5e521b8a"

#define NS_IWORKERSCOPE_IID \
  {0x5c55ea4b, 0xe4ac, 0x4ceb, \
    { 0xbf, 0xeb, 0x46, 0xbd, 0x5e, 0x52, 0x1b, 0x8a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerScope : public nsIWorkerGlobalScope {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERSCOPE_IID)

  /* void postMessage (); */
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /* attribute nsIDOMEventListener onmessage; */
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) = 0;

  /* attribute nsIDOMEventListener onclose; */
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerScope, NS_IWORKERSCOPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERSCOPE \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage); \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage); \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose); \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERSCOPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) { return _to PostMessage(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) { return _to GetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) { return _to SetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) { return _to GetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) { return _to SetOnclose(aOnclose); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERSCOPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessage(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnclose(nsIDOMEventListener **aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclose(aOnclose); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnclose(nsIDOMEventListener *aOnclose) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclose(aOnclose); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerScope : public nsIWorkerScope
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERSCOPE

  nsWorkerScope();

private:
  ~nsWorkerScope();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerScope, nsIWorkerScope)

nsWorkerScope::nsWorkerScope()
{
  /* member initializers and constructor code */
}

nsWorkerScope::~nsWorkerScope()
{
  /* destructor code */
}

/* void postMessage (); */
NS_IMETHODIMP nsWorkerScope::PostMessage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsWorkerScope::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onmessage; */
NS_IMETHODIMP nsWorkerScope::GetOnmessage(nsIDOMEventListener **aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWorkerScope::SetOnmessage(nsIDOMEventListener *aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onclose; */
NS_IMETHODIMP nsWorkerScope::GetOnclose(nsIDOMEventListener **aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWorkerScope::SetOnclose(nsIDOMEventListener *aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAbstractWorker */
#define NS_IABSTRACTWORKER_IID_STR "b90b7561-b5e2-4545-84b0-280dbaaa94ea"

#define NS_IABSTRACTWORKER_IID \
  {0xb90b7561, 0xb5e2, 0x4545, \
    { 0x84, 0xb0, 0x28, 0x0d, 0xba, 0xaa, 0x94, 0xea }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAbstractWorker : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IABSTRACTWORKER_IID)

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAbstractWorker, NS_IABSTRACTWORKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIABSTRACTWORKER \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIABSTRACTWORKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return _to SetOnerror(aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIABSTRACTWORKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener **aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAbstractWorker : public nsIAbstractWorker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIABSTRACTWORKER

  nsAbstractWorker();

private:
  ~nsAbstractWorker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAbstractWorker, nsIAbstractWorker)

nsAbstractWorker::nsAbstractWorker()
{
  /* member initializers and constructor code */
}

nsAbstractWorker::~nsAbstractWorker()
{
  /* destructor code */
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsAbstractWorker::GetOnerror(nsIDOMEventListener **aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAbstractWorker::SetOnerror(nsIDOMEventListener *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorker */
#define NS_IWORKER_IID_STR "daf945c3-8d29-4724-8939-dd383f7d27a7"

#define NS_IWORKER_IID \
  {0xdaf945c3, 0x8d29, 0x4724, \
    { 0x89, 0x39, 0xdd, 0x38, 0x3f, 0x7d, 0x27, 0xa7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorker : public nsIAbstractWorker {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKER_IID)

  /* void postMessage (); */
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) = 0;

  /* attribute nsIDOMEventListener onmessage; */
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) = 0;

  /* void terminate (); */
  NS_SCRIPTABLE NS_IMETHOD Terminate(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorker, NS_IWORKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKER \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage); \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage); \
  NS_SCRIPTABLE NS_IMETHOD Terminate(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) { return _to PostMessage(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) { return _to GetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) { return _to SetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD Terminate(void) { return _to Terminate(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostMessage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessage(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnmessage(nsIDOMEventListener **aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnmessage(nsIDOMEventListener *aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmessage(aOnmessage); } \
  NS_SCRIPTABLE NS_IMETHOD Terminate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Terminate(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorker : public nsIWorker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKER

  nsWorker();

private:
  ~nsWorker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorker, nsIWorker)

nsWorker::nsWorker()
{
  /* member initializers and constructor code */
}

nsWorker::~nsWorker()
{
  /* destructor code */
}

/* void postMessage (); */
NS_IMETHODIMP nsWorker::PostMessage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onmessage; */
NS_IMETHODIMP nsWorker::GetOnmessage(nsIDOMEventListener **aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWorker::SetOnmessage(nsIDOMEventListener *aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void terminate (); */
NS_IMETHODIMP nsWorker::Terminate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerFactory */
#define NS_IWORKERFACTORY_IID_STR "cfc4bb32-ca83-4d58-9b6f-66f8054a333a"

#define NS_IWORKERFACTORY_IID \
  {0xcfc4bb32, 0xca83, 0x4d58, \
    { 0x9b, 0x6f, 0x66, 0xf8, 0x05, 0x4a, 0x33, 0x3a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWorkerFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERFACTORY_IID)

  /* nsIWorker newChromeWorker (); */
  NS_SCRIPTABLE NS_IMETHOD NewChromeWorker(nsIWorker **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerFactory, NS_IWORKERFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERFACTORY \
  NS_SCRIPTABLE NS_IMETHOD NewChromeWorker(nsIWorker **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewChromeWorker(nsIWorker **_retval NS_OUTPARAM) { return _to NewChromeWorker(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewChromeWorker(nsIWorker **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChromeWorker(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerFactory : public nsIWorkerFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERFACTORY

  nsWorkerFactory();

private:
  ~nsWorkerFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWorkerFactory, nsIWorkerFactory)

nsWorkerFactory::nsWorkerFactory()
{
  /* member initializers and constructor code */
}

nsWorkerFactory::~nsWorkerFactory()
{
  /* destructor code */
}

/* nsIWorker newChromeWorker (); */
NS_IMETHODIMP nsWorkerFactory::NewChromeWorker(nsIWorker **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_WORKERFACTORY_CONTRACTID \
"@mozilla.org/threads/workerfactory;1"

#endif /* __gen_nsIDOMWorkers_h__ */
