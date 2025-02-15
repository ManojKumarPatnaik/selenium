/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-2.0-xr-w32-bld/build/toolkit/components/places/public/nsINavHistoryService.idl
 */

#ifndef __gen_nsINavHistoryService_h__
#define __gen_nsINavHistoryService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIFile; /* forward declaration */

class nsINavHistoryContainerResultNode; /* forward declaration */

class nsINavHistoryQueryResultNode; /* forward declaration */

class nsINavHistoryQuery; /* forward declaration */

class nsINavHistoryQueryOptions; /* forward declaration */

class nsINavHistoryResult; /* forward declaration */

class nsINavHistoryBatchCallback; /* forward declaration */


/* starting interface:    nsINavHistoryResultNode */
#define NS_INAVHISTORYRESULTNODE_IID_STR "081452e5-be5c-4038-a5ea-f1f34cb6fd81"

#define NS_INAVHISTORYRESULTNODE_IID \
  {0x081452e5, 0xbe5c, 0x4038, \
    { 0xa5, 0xea, 0xf1, 0xf3, 0x4c, 0xb6, 0xfd, 0x81 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryResultNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTNODE_IID)

  /**
   * Indentifies the parent result node in the result set. This is null for
   * top level nodes.
   */
  /* readonly attribute nsINavHistoryContainerResultNode parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsINavHistoryContainerResultNode **aParent) = 0;

  /**
   * The history-result to which this node belongs.
   */
  /* readonly attribute nsINavHistoryResult parentResult; */
  NS_SCRIPTABLE NS_IMETHOD GetParentResult(nsINavHistoryResult **aParentResult) = 0;

  /**
   * URI of the resource in question. For visits and URLs, this is the URL of
   * the page. For folders and queries, this is the place: URI of the
   * corresponding folder or query. This may be empty for other types of
   * objects like host containers.
   */
  /* readonly attribute AUTF8String uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsACString & aUri) = 0;

  /**
   * Identifies the type of this node. This node can then be QI-ed to the
   * corresponding specialized result node interface.
   */
  enum { RESULT_TYPE_URI = 0U };

  enum { RESULT_TYPE_VISIT = 1U };

  enum { RESULT_TYPE_FULL_VISIT = 2U };

  enum { RESULT_TYPE_DYNAMIC_CONTAINER = 4U };

  enum { RESULT_TYPE_QUERY = 5U };

  enum { RESULT_TYPE_FOLDER = 6U };

  enum { RESULT_TYPE_SEPARATOR = 7U };

  enum { RESULT_TYPE_FOLDER_SHORTCUT = 9U };

  /* readonly attribute unsigned long type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) = 0;

  /**
   * Title of the web page, or of the node's query (day, host, folder, etc)
   */
  /* readonly attribute AUTF8String title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsACString & aTitle) = 0;

  /**
   * Total number of times the URI has ever been accessed. For hosts, this
   * is the total of the children under it, NOT the total times the host has
   * been accessed (this would require an additional query, so is not given
   * by default when most of the time it is never needed).
   */
  /* readonly attribute unsigned long accessCount; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessCount(PRUint32 *aAccessCount) = 0;

  /**
   * This is the time the user accessed the page.
   *
   * If this is a visit, it is the exact time that the page visit occurred.
   *
   * If this is a URI, it is the most recent time that the URI was visited.
   * Even if you ask for all URIs for a given date range long ago, this might
   * contain today's date if the URI was visited today.
   *
   * For hosts, or other node types with children, this is the most recent
   * access time for any of the children.
   *
   * For days queries this is the respective endTime - a maximum possible
   * visit time to fit in the day range.
   */
  /* readonly attribute PRTime time; */
  NS_SCRIPTABLE NS_IMETHOD GetTime(PRTime *aTime) = 0;

  /**
   * This URI can be used as an image source URI and will give you the favicon
   * for the page. It is *not* the URI of the favicon, but rather something
   * that will resolve to the actual image.
   *
   * In most cases, this is an annotation URI that will query the favicon
   * service. If the entry has no favicon, this is the chrome URI of the
   * default favicon. If the favicon originally lived in chrome, this will
   * be the original chrome URI of the icon.
   */
  /* readonly attribute AUTF8String icon; */
  NS_SCRIPTABLE NS_IMETHOD GetIcon(nsACString & aIcon) = 0;

  /**
   * This is the number of levels between this node and the top of the
   * hierarchy. The members of result.children have indentLevel = 0, their
   * children have indentLevel = 1, etc. The indent level of the root node is
   * set to -1.
   */
  /* readonly attribute long indentLevel; */
  NS_SCRIPTABLE NS_IMETHOD GetIndentLevel(PRInt32 *aIndentLevel) = 0;

  /**
   * When this item is in a bookmark folder (parent is of type folder), this is
   * the index into that folder of this node. These indices start at 0 and
   * increase in the order that they appear in the bookmark folder. For items
   * that are not in a bookmark folder, this value is -1.
   */
  /* readonly attribute long bookmarkIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIndex(PRInt32 *aBookmarkIndex) = 0;

  /**
   * If the node is an item (bookmark, folder or a separator) this value is the
   * row ID of that bookmark in the database. For other nodes, this value is
   * set to -1.
   */
  /* readonly attribute long long itemId; */
  NS_SCRIPTABLE NS_IMETHOD GetItemId(PRInt64 *aItemId) = 0;

  /**
   * If the node is an item (bookmark, folder or a separator) this value is the 
   * time that the item was created. For other nodes, this value is 0.
   */
  /* readonly attribute PRTime dateAdded; */
  NS_SCRIPTABLE NS_IMETHOD GetDateAdded(PRTime *aDateAdded) = 0;

  /**
   * If the node is an item (bookmark, folder or a separator) this value is the 
   * time that the item was last modified. For other nodes, this value is 0.
   *
   *  @note When an item is added lastModified is set to the same value as
   *        dateAdded.
   */
  /* readonly attribute PRTime lastModified; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified) = 0;

  /**
   * For uri nodes, this is a sorted list of the tags, delimited with commans,
   * for the uri represented by this node. Otherwise this is an empty string.
   */
  /* readonly attribute AString tags; */
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsAString & aTags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultNode, NS_INAVHISTORYRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTNODE \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsINavHistoryContainerResultNode **aParent); \
  NS_SCRIPTABLE NS_IMETHOD GetParentResult(nsINavHistoryResult **aParentResult); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsACString & aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsACString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessCount(PRUint32 *aAccessCount); \
  NS_SCRIPTABLE NS_IMETHOD GetTime(PRTime *aTime); \
  NS_SCRIPTABLE NS_IMETHOD GetIcon(nsACString & aIcon); \
  NS_SCRIPTABLE NS_IMETHOD GetIndentLevel(PRInt32 *aIndentLevel); \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIndex(PRInt32 *aBookmarkIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetItemId(PRInt64 *aItemId); \
  NS_SCRIPTABLE NS_IMETHOD GetDateAdded(PRTime *aDateAdded); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified); \
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsAString & aTags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsINavHistoryContainerResultNode **aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentResult(nsINavHistoryResult **aParentResult) { return _to GetParentResult(aParentResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsACString & aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsACString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessCount(PRUint32 *aAccessCount) { return _to GetAccessCount(aAccessCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTime(PRTime *aTime) { return _to GetTime(aTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIcon(nsACString & aIcon) { return _to GetIcon(aIcon); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndentLevel(PRInt32 *aIndentLevel) { return _to GetIndentLevel(aIndentLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIndex(PRInt32 *aBookmarkIndex) { return _to GetBookmarkIndex(aBookmarkIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemId(PRInt64 *aItemId) { return _to GetItemId(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD GetDateAdded(PRTime *aDateAdded) { return _to GetDateAdded(aDateAdded); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsAString & aTags) { return _to GetTags(aTags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsINavHistoryContainerResultNode **aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentResult(nsINavHistoryResult **aParentResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentResult(aParentResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsACString & aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsACString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessCount(PRUint32 *aAccessCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessCount(aAccessCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTime(PRTime *aTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTime(aTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIcon(nsACString & aIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcon(aIcon); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndentLevel(PRInt32 *aIndentLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndentLevel(aIndentLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIndex(PRInt32 *aBookmarkIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkIndex(aBookmarkIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemId(PRInt64 *aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemId(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD GetDateAdded(PRTime *aDateAdded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDateAdded(aDateAdded); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsAString & aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultNode : public nsINavHistoryResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTNODE

  nsNavHistoryResultNode();

private:
  ~nsNavHistoryResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResultNode, nsINavHistoryResultNode)

nsNavHistoryResultNode::nsNavHistoryResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultNode::~nsNavHistoryResultNode()
{
  /* destructor code */
}

/* readonly attribute nsINavHistoryContainerResultNode parent; */
NS_IMETHODIMP nsNavHistoryResultNode::GetParent(nsINavHistoryContainerResultNode **aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryResult parentResult; */
NS_IMETHODIMP nsNavHistoryResultNode::GetParentResult(nsINavHistoryResult **aParentResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String uri; */
NS_IMETHODIMP nsNavHistoryResultNode::GetUri(nsACString & aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsNavHistoryResultNode::GetType(PRUint32 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String title; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTitle(nsACString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long accessCount; */
NS_IMETHODIMP nsNavHistoryResultNode::GetAccessCount(PRUint32 *aAccessCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime time; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTime(PRTime *aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String icon; */
NS_IMETHODIMP nsNavHistoryResultNode::GetIcon(nsACString & aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long indentLevel; */
NS_IMETHODIMP nsNavHistoryResultNode::GetIndentLevel(PRInt32 *aIndentLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long bookmarkIndex; */
NS_IMETHODIMP nsNavHistoryResultNode::GetBookmarkIndex(PRInt32 *aBookmarkIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long itemId; */
NS_IMETHODIMP nsNavHistoryResultNode::GetItemId(PRInt64 *aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime dateAdded; */
NS_IMETHODIMP nsNavHistoryResultNode::GetDateAdded(PRTime *aDateAdded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModified; */
NS_IMETHODIMP nsNavHistoryResultNode::GetLastModified(PRTime *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tags; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTags(nsAString & aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryVisitResultNode */
#define NS_INAVHISTORYVISITRESULTNODE_IID_STR "8e2c5a86-b33d-4fa6-944b-559af7e95fcd"

#define NS_INAVHISTORYVISITRESULTNODE_IID \
  {0x8e2c5a86, 0xb33d, 0x4fa6, \
    { 0x94, 0x4b, 0x55, 0x9a, 0xf7, 0xe9, 0x5f, 0xcd }}

/**
 * When you request RESULT_TYPE_VISIT from query options, you will get this
 * interface for each item, which includes the session ID so that we can
 * group items from the same session together.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryVisitResultNode : public nsINavHistoryResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYVISITRESULTNODE_IID)

  /**
   * This indicates the session ID of the * visit. This is used for session
   * grouping when a tree view is sorted by date.
   */
  /* readonly attribute long long sessionId; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryVisitResultNode, NS_INAVHISTORYVISITRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYVISITRESULTNODE \
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYVISITRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId) { return _to GetSessionId(aSessionId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYVISITRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionId(aSessionId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryVisitResultNode : public nsINavHistoryVisitResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYVISITRESULTNODE

  nsNavHistoryVisitResultNode();

private:
  ~nsNavHistoryVisitResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryVisitResultNode, nsINavHistoryVisitResultNode)

nsNavHistoryVisitResultNode::nsNavHistoryVisitResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryVisitResultNode::~nsNavHistoryVisitResultNode()
{
  /* destructor code */
}

/* readonly attribute long long sessionId; */
NS_IMETHODIMP nsNavHistoryVisitResultNode::GetSessionId(PRInt64 *aSessionId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryFullVisitResultNode */
#define NS_INAVHISTORYFULLVISITRESULTNODE_IID_STR "c49fd9d5-56e2-43eb-932c-f933f28cba85"

#define NS_INAVHISTORYFULLVISITRESULTNODE_IID \
  {0xc49fd9d5, 0x56e2, 0x43eb, \
    { 0x93, 0x2c, 0xf9, 0x33, 0xf2, 0x8c, 0xba, 0x85 }}

/**
 * This structure will be returned when you request RESULT_TYPE_FULL_VISIT in
 * the query options. This includes uncommonly used information about each
 * visit.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryFullVisitResultNode : public nsINavHistoryVisitResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYFULLVISITRESULTNODE_IID)

  /**
   * This indicates the visit ID of the visit.
   */
  /* readonly attribute long long visitId; */
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId) = 0;

  /**
   * This indicates the referring visit ID of the visit. The referrer should
   * have the same sessionId.
   */
  /* readonly attribute long long referringVisitId; */
  NS_SCRIPTABLE NS_IMETHOD GetReferringVisitId(PRInt64 *aReferringVisitId) = 0;

  /**
   * Indicates the transition type of the visit.
   * One of nsINavHistoryService.TRANSITION_*
   */
  /* readonly attribute long transitionType; */
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRInt32 *aTransitionType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryFullVisitResultNode, NS_INAVHISTORYFULLVISITRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYFULLVISITRESULTNODE \
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId); \
  NS_SCRIPTABLE NS_IMETHOD GetReferringVisitId(PRInt64 *aReferringVisitId); \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRInt32 *aTransitionType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYFULLVISITRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId) { return _to GetVisitId(aVisitId); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferringVisitId(PRInt64 *aReferringVisitId) { return _to GetReferringVisitId(aReferringVisitId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRInt32 *aTransitionType) { return _to GetTransitionType(aTransitionType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYFULLVISITRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitId(aVisitId); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferringVisitId(PRInt64 *aReferringVisitId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferringVisitId(aReferringVisitId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRInt32 *aTransitionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitionType(aTransitionType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryFullVisitResultNode : public nsINavHistoryFullVisitResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYFULLVISITRESULTNODE

  nsNavHistoryFullVisitResultNode();

private:
  ~nsNavHistoryFullVisitResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryFullVisitResultNode, nsINavHistoryFullVisitResultNode)

nsNavHistoryFullVisitResultNode::nsNavHistoryFullVisitResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryFullVisitResultNode::~nsNavHistoryFullVisitResultNode()
{
  /* destructor code */
}

/* readonly attribute long long visitId; */
NS_IMETHODIMP nsNavHistoryFullVisitResultNode::GetVisitId(PRInt64 *aVisitId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long referringVisitId; */
NS_IMETHODIMP nsNavHistoryFullVisitResultNode::GetReferringVisitId(PRInt64 *aReferringVisitId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long transitionType; */
NS_IMETHODIMP nsNavHistoryFullVisitResultNode::GetTransitionType(PRInt32 *aTransitionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryContainerResultNode */
#define NS_INAVHISTORYCONTAINERRESULTNODE_IID_STR "55829318-0f6c-4503-8739-84231f3a6793"

#define NS_INAVHISTORYCONTAINERRESULTNODE_IID \
  {0x55829318, 0x0f6c, 0x4503, \
    { 0x87, 0x39, 0x84, 0x23, 0x1f, 0x3a, 0x67, 0x93 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryContainerResultNode : public nsINavHistoryResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYCONTAINERRESULTNODE_IID)

  /**
 * Base class for container results. This includes all types of groupings.
 * Bookmark folders and places queries will be QueryResultNodes which extends
 * these items.
 */
/**
   * Set this to allow descent into the container. When closed, attempting
   * to call getChildren or childCount will result in an error. You should
   * set this to false when you are done reading.
   *
   * For HOST and DAY groupings, doing this is free since the children have
   * been precomputed. For queries and bookmark folders, being open means they
   * will keep themselves up-to-date by listening for updates and re-querying
   * as needed.
   */
  /* attribute boolean containerOpen; */
  NS_SCRIPTABLE NS_IMETHOD GetContainerOpen(PRBool *aContainerOpen) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContainerOpen(PRBool aContainerOpen) = 0;

  /**
   * Indicates whether the container is closed, loading, or opened.  Loading
   * implies that the container has been opened asynchronously and has not yet
   * fully opened.
   */
  /* readonly attribute unsigned short state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint16 *aState) = 0;

  enum { STATE_CLOSED = 0U };

  enum { STATE_LOADING = 1U };

  enum { STATE_OPENED = 2U };

  /**
   * This indicates whether this node "may" have children, and can be used
   * when the container is open or closed. When the container is closed, it
   * will give you an exact answer if the node can easily be populated (for
   * example, a bookmark folder). If not (for example, a complex history query),
   * it will return true. When the container is open, it will always be
   * accurate. It is intended to be used to see if we should draw the "+" next
   * to a tree item.
   */
  /* readonly attribute boolean hasChildren; */
  NS_SCRIPTABLE NS_IMETHOD GetHasChildren(PRBool *aHasChildren) = 0;

  /**
   * This gives you the children of the nodes. It is preferrable to use this
   * interface over the array one, since it avoids creating an nsIArray object
   * and the interface is already the correct type.
   *
   * @throws NS_ERROR_NOT_AVAILABLE if containerOpen is false.
   */
  /* readonly attribute unsigned long childCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) = 0;

  /* nsINavHistoryResultNode getChild (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetChild(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM) = 0;

  /**
   * Get the index of a direct child in this container.
   *
   * @param aNode
   *        a result node.
   *
   * @return aNode's index in this container.
   * @throws NS_ERROR_NOT_AVAILABLE if containerOpen is false.
   * @throws NS_ERROR_INVALID_ARG if aNode isn't a direct child of this
   * container.
   */
  /* unsigned long getChildIndex (in nsINavHistoryResultNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Look for a node in the container by some of its details.  Does not search
   * closed containers.
   *
   * @param aURI
   *        the node's uri attribute value
   * @param aTime
   *        the node's time attribute value.
   * @param aItemId
   *        the node's itemId attribute value.
   * @param aRecursive
   *        whether or not to search recursively.
   *
   * @throws NS_ERROR_NOT_AVAILABLE if this container is closed.
   * @return a result node that matches the given details if any, null
   *         otherwise.
   */
  /* nsINavHistoryResultNode findNodeByDetails (in AUTF8String aURIString, in PRTime aTime, in long long aItemId, in boolean aRecursive); */
  NS_SCRIPTABLE NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, PRInt64 aItemId, PRBool aRecursive, nsINavHistoryResultNode **_retval NS_OUTPARAM) = 0;

  /**
   * Returns false if this node's list of children can be modified
   * (adding or removing children, or reordering children), or true if
   * the UI should not allow the list of children to be modified.
   * This is false for bookmark folder nodes unless setFolderReadOnly() has
   * been called to override it, and true for non-folder nodes.
   */
  /* readonly attribute boolean childrenReadOnly; */
  NS_SCRIPTABLE NS_IMETHOD GetChildrenReadOnly(PRBool *aChildrenReadOnly) = 0;

  /**
   * This is a string representing the dynamic container API service that is
   * responsible for this container. This throws if if the node is not a dynamic
   * container.
   */
  /* readonly attribute AUTF8String dynamicContainerType; */
  NS_SCRIPTABLE NS_IMETHOD GetDynamicContainerType(nsACString & aDynamicContainerType) = 0;

  /**
   * Appends a full visit node to this container and returns it. For the dynamic
   * container API. TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening()
   * ONLY, and only for non-bookmark-folder containers.
   *
   * @see nsINavHistoryURIResultNode for parameters.
   */
  /* nsINavHistoryResultNode appendURINode (in AUTF8String aURI, in AUTF8String aTitle, in PRUint32 aAccessCount, in PRTime aTime, in AUTF8String aIconURI); */
  NS_SCRIPTABLE NS_IMETHOD AppendURINode(const nsACString & aURI, const nsACString & aTitle, PRUint32 aAccessCount, PRTime aTime, const nsACString & aIconURI, nsINavHistoryResultNode **_retval NS_OUTPARAM) = 0;

  /**
   * Appends a full visit node to this container and returns it. For the dynamic
   * container API. TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening()
   * ONLY, and only for non-bookmark-folder containers.
   *
   * @see nsINavHistoryVisitResultNode for parameters.
   *
   * UNTESTED: Container API functions are commented out until we can test
   */
/**
   * Appends a full visit node to this container and returns it. For the dynamic
   * container API. TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening()
   * ONLY, and only for non-bookmark-folder containers.
   *
   * @see nsINavHistoryFullVisitResultNode for parameters.
   *
   * UNTESTED: Container API functions are commented out until we can test
   */
/**
   * Appends a container node to this container and returns it. For the dynamic
   * container API. TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening()
   * ONLY, and only for non-bookmark-folder containers.
   *
   * aContainerType should be RESULT_TYPE_DYNAMIC_CONTAINER.
   * When type is dynamic container you must
   * specify a dynamic container type, otherwise, the dynamic container type must
   * be null. Use appendQueryNode and appendFolderNode for the other container
   * types.
   *
   * UNTESTED: Container API functions are commented out until we can test
   */
/**
   * Appends a query node to this container and returns it. For the dynamic
   * container API. TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening()
   * ONLY, and only for non-bookmark-folder containers.
   *
   * Normally you should supply an empty string for IconURI and it will take
   * the default query icon for the current theme.
   *
   * UNTESTED: Container API functions are commented out until we can test
   */
/**
   * Appends a bookmark folder node to this container and returns it. For the
   * dynamic container API. TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening()
   * ONLY, and only for non-bookmark-folder containers.
   *
   * All container attributes will come from the boomkarks service for this
   * folder.
   */
  /* nsINavHistoryContainerResultNode appendFolderNode (in PRInt64 aFolderId); */
  NS_SCRIPTABLE NS_IMETHOD AppendFolderNode(PRInt64 aFolderId, nsINavHistoryContainerResultNode **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryContainerResultNode, NS_INAVHISTORYCONTAINERRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYCONTAINERRESULTNODE \
  NS_SCRIPTABLE NS_IMETHOD GetContainerOpen(PRBool *aContainerOpen); \
  NS_SCRIPTABLE NS_IMETHOD SetContainerOpen(PRBool aContainerOpen); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint16 *aState); \
  NS_SCRIPTABLE NS_IMETHOD GetHasChildren(PRBool *aHasChildren); \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount); \
  NS_SCRIPTABLE NS_IMETHOD GetChild(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, PRInt64 aItemId, PRBool aRecursive, nsINavHistoryResultNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChildrenReadOnly(PRBool *aChildrenReadOnly); \
  NS_SCRIPTABLE NS_IMETHOD GetDynamicContainerType(nsACString & aDynamicContainerType); \
  NS_SCRIPTABLE NS_IMETHOD AppendURINode(const nsACString & aURI, const nsACString & aTitle, PRUint32 aAccessCount, PRTime aTime, const nsACString & aIconURI, nsINavHistoryResultNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendFolderNode(PRInt64 aFolderId, nsINavHistoryContainerResultNode **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYCONTAINERRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContainerOpen(PRBool *aContainerOpen) { return _to GetContainerOpen(aContainerOpen); } \
  NS_SCRIPTABLE NS_IMETHOD SetContainerOpen(PRBool aContainerOpen) { return _to SetContainerOpen(aContainerOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint16 *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasChildren(PRBool *aHasChildren) { return _to GetHasChildren(aHasChildren); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChild(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return _to GetChild(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM) { return _to GetChildIndex(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, PRInt64 aItemId, PRBool aRecursive, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return _to FindNodeByDetails(aURIString, aTime, aItemId, aRecursive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildrenReadOnly(PRBool *aChildrenReadOnly) { return _to GetChildrenReadOnly(aChildrenReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD GetDynamicContainerType(nsACString & aDynamicContainerType) { return _to GetDynamicContainerType(aDynamicContainerType); } \
  NS_SCRIPTABLE NS_IMETHOD AppendURINode(const nsACString & aURI, const nsACString & aTitle, PRUint32 aAccessCount, PRTime aTime, const nsACString & aIconURI, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return _to AppendURINode(aURI, aTitle, aAccessCount, aTime, aIconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendFolderNode(PRInt64 aFolderId, nsINavHistoryContainerResultNode **_retval NS_OUTPARAM) { return _to AppendFolderNode(aFolderId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYCONTAINERRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContainerOpen(PRBool *aContainerOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainerOpen(aContainerOpen); } \
  NS_SCRIPTABLE NS_IMETHOD SetContainerOpen(PRBool aContainerOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainerOpen(aContainerOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint16 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasChildren(PRBool *aHasChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasChildren(aHasChildren); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChild(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChild(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildIndex(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, PRInt64 aItemId, PRBool aRecursive, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNodeByDetails(aURIString, aTime, aItemId, aRecursive, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildrenReadOnly(PRBool *aChildrenReadOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildrenReadOnly(aChildrenReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD GetDynamicContainerType(nsACString & aDynamicContainerType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDynamicContainerType(aDynamicContainerType); } \
  NS_SCRIPTABLE NS_IMETHOD AppendURINode(const nsACString & aURI, const nsACString & aTitle, PRUint32 aAccessCount, PRTime aTime, const nsACString & aIconURI, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendURINode(aURI, aTitle, aAccessCount, aTime, aIconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendFolderNode(PRInt64 aFolderId, nsINavHistoryContainerResultNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendFolderNode(aFolderId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryContainerResultNode : public nsINavHistoryContainerResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYCONTAINERRESULTNODE

  nsNavHistoryContainerResultNode();

private:
  ~nsNavHistoryContainerResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryContainerResultNode, nsINavHistoryContainerResultNode)

nsNavHistoryContainerResultNode::nsNavHistoryContainerResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryContainerResultNode::~nsNavHistoryContainerResultNode()
{
  /* destructor code */
}

/* attribute boolean containerOpen; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetContainerOpen(PRBool *aContainerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryContainerResultNode::SetContainerOpen(PRBool aContainerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short state; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetState(PRUint16 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasChildren; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetHasChildren(PRBool *aHasChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildCount(PRUint32 *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode getChild (in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChild(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getChildIndex (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildIndex(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode findNodeByDetails (in AUTF8String aURIString, in PRTime aTime, in long long aItemId, in boolean aRecursive); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::FindNodeByDetails(const nsACString & aURIString, PRTime aTime, PRInt64 aItemId, PRBool aRecursive, nsINavHistoryResultNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean childrenReadOnly; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildrenReadOnly(PRBool *aChildrenReadOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String dynamicContainerType; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetDynamicContainerType(nsACString & aDynamicContainerType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode appendURINode (in AUTF8String aURI, in AUTF8String aTitle, in PRUint32 aAccessCount, in PRTime aTime, in AUTF8String aIconURI); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::AppendURINode(const nsACString & aURI, const nsACString & aTitle, PRUint32 aAccessCount, PRTime aTime, const nsACString & aIconURI, nsINavHistoryResultNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryContainerResultNode appendFolderNode (in PRInt64 aFolderId); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::AppendFolderNode(PRInt64 aFolderId, nsINavHistoryContainerResultNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQueryResultNode */
#define NS_INAVHISTORYQUERYRESULTNODE_IID_STR "ea17745a-1852-4155-a98f-d1dd1763b3df"

#define NS_INAVHISTORYQUERYRESULTNODE_IID \
  {0xea17745a, 0x1852, 0x4155, \
    { 0xa9, 0x8f, 0xd1, 0xdd, 0x17, 0x63, 0xb3, 0xdf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryQueryResultNode : public nsINavHistoryContainerResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERYRESULTNODE_IID)

  /**
   * Clears all children of this container. For the dynamic container API.
   * TO BE CALLED FROM nsIDynamicContainer::OnContainerOpening and
   * nsIDynamicContainer::OnContainerClosed ONLY, and valid only for
   * non-bookmark-folder containers.
   *
   * UNTESTED: Container API functions are commented out until we can test
   */
/**
 * Used for places queries and as a base for bookmark folders.
 *
 * Note that if you request places to *not* be expanded in the options that
 * generated this node, this item will report it has no children and never try
 * to populate itself.
 */
/**
   * Get the queries which build this node's children.
   * Only valid for RESULT_TYPE_QUERY nodes.
   */
  /* void getQueries ([optional] out unsigned long queryCount, [array, size_is (queryCount), retval] out nsINavHistoryQuery queries); */
  NS_SCRIPTABLE NS_IMETHOD GetQueries(PRUint32 *queryCount NS_OUTPARAM, nsINavHistoryQuery ***queries NS_OUTPARAM) = 0;

  /**
   * Get the options which group this node's children.
   * Only valid for RESULT_TYPE_QUERY nodes.
   */
  /* readonly attribute nsINavHistoryQueryOptions queryOptions; */
  NS_SCRIPTABLE NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions **aQueryOptions) = 0;

  /**
   * For both simple folder nodes and simple-folder-query nodes, this is set
   * to the concrete itemId of the folder. Otherwise, this is set to -1.
   */
  /* readonly attribute long long folderItemId; */
  NS_SCRIPTABLE NS_IMETHOD GetFolderItemId(PRInt64 *aFolderItemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQueryResultNode, NS_INAVHISTORYQUERYRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERYRESULTNODE \
  NS_SCRIPTABLE NS_IMETHOD GetQueries(PRUint32 *queryCount NS_OUTPARAM, nsINavHistoryQuery ***queries NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions **aQueryOptions); \
  NS_SCRIPTABLE NS_IMETHOD GetFolderItemId(PRInt64 *aFolderItemId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERYRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetQueries(PRUint32 *queryCount NS_OUTPARAM, nsINavHistoryQuery ***queries NS_OUTPARAM) { return _to GetQueries(queryCount, queries); } \
  NS_SCRIPTABLE NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions **aQueryOptions) { return _to GetQueryOptions(aQueryOptions); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderItemId(PRInt64 *aFolderItemId) { return _to GetFolderItemId(aFolderItemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERYRESULTNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetQueries(PRUint32 *queryCount NS_OUTPARAM, nsINavHistoryQuery ***queries NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueries(queryCount, queries); } \
  NS_SCRIPTABLE NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions **aQueryOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryOptions(aQueryOptions); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderItemId(PRInt64 *aFolderItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderItemId(aFolderItemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQueryResultNode : public nsINavHistoryQueryResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERYRESULTNODE

  nsNavHistoryQueryResultNode();

private:
  ~nsNavHistoryQueryResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryQueryResultNode, nsINavHistoryQueryResultNode)

nsNavHistoryQueryResultNode::nsNavHistoryQueryResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryQueryResultNode::~nsNavHistoryQueryResultNode()
{
  /* destructor code */
}

/* void getQueries ([optional] out unsigned long queryCount, [array, size_is (queryCount), retval] out nsINavHistoryQuery queries); */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetQueries(PRUint32 *queryCount NS_OUTPARAM, nsINavHistoryQuery ***queries NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryQueryOptions queryOptions; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetQueryOptions(nsINavHistoryQueryOptions **aQueryOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long folderItemId; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetFolderItemId(PRInt64 *aFolderItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResultObserver */
#define NS_INAVHISTORYRESULTOBSERVER_IID_STR "9ea86387-6a30-4ee2-b70d-26fbb718902f"

#define NS_INAVHISTORYRESULTOBSERVER_IID \
  {0x9ea86387, 0x6a30, 0x4ee2, \
    { 0xb7, 0x0d, 0x26, 0xfb, 0xb7, 0x18, 0x90, 0x2f }}

/**
 * Allows clients to observe what is happening to a result as it updates itself
 * according to history and bookmark system events. Register this observer on a
 * result using nsINavHistoryResult::addObserver.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryResultObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTOBSERVER_IID)

  /**
   * Called when 'aItem' is inserted into 'aParent' at index 'aNewIndex'.
   * The item previously at index (if any) and everything below it will have
   * been shifted down by one. The item may be a container or a leaf.
   */
  /* void nodeInserted (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aNode, in unsigned long aNewIndex); */
  NS_SCRIPTABLE NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, PRUint32 aNewIndex) = 0;

  /**
   * Called whan 'aItem' is removed from 'aParent' at 'aOldIndex'. The item
   * may be a container or a leaf. This function will be called after the item
   * has been removed from its parent list, but before anything else (including
   * NULLing out the item's parent) has happened.
   */
  /* void nodeRemoved (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aItem, in unsigned long aOldIndex); */
  NS_SCRIPTABLE NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, PRUint32 aOldIndex) = 0;

  /**
   * Called whan 'aItem' is moved from 'aOldParent' at 'aOldIndex' to
   * aNewParent at aNewIndex. The item may be a container or a leaf.
   *
   * XXX: at the moment, this method is called only when an item is moved
   * within the same container. When an item is moved between containers,
   * a new node is created for the item, and the itemRemoved/itemAdded methods
   * are used.
   */
  /* void nodeMoved (in nsINavHistoryResultNode aNode, in nsINavHistoryContainerResultNode aOldParent, in unsigned long aOldIndex, in nsINavHistoryContainerResultNode aNewParent, in unsigned long aNewIndex); */
  NS_SCRIPTABLE NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, PRUint32 aOldIndex, nsINavHistoryContainerResultNode *aNewParent, PRUint32 aNewIndex) = 0;

  /**
   * Called right after aNode's title has changed.
   * 
   * @param aNode
   *        a result node
   * @param aNewTitle
   *        the new title
   */
  /* void nodeTitleChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewTitle); */
  NS_SCRIPTABLE NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) = 0;

  /**
   * Called right after aNode's uri property has changed.
   * 
   * @param aNode
   *        a result node
   * @param aNewURI
   *        the new uri
   */
  /* void nodeURIChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewURI); */
  NS_SCRIPTABLE NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) = 0;

  /**
   * Called right after aNode's icon property has changed.
   *
   * @param aNode
   *        a result node
   *
   * @note: The new icon is accessible through aNode.icon.
   */
  /* void nodeIconChanged (in nsINavHistoryResultNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) = 0;

  /**
   * Called right after aNode's time property or accessCount property, or both,
   * have changed.
   *
   * @param aNode
   *        a uri result node
   * @param aNewVisitDate
   *        the new visit date
   * @param aNewAccessCount
   *        the new access-count
   */
  /* void nodeHistoryDetailsChanged (in nsINavHistoryResultNode aNode, in PRTime aNewVisitDate, in unsigned long aNewAccessCount); */
  NS_SCRIPTABLE NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, PRUint32 aNewAccessCount) = 0;

  /**
   * Called when the tags set on the uri represented by aNode have changed.
   *
   * @param aNode
   *        a uri result node
   *
   * @note: The new tags list is accessible through aNode.tags.
   */
  /* void nodeTagsChanged (in nsINavHistoryResultNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) = 0;

  /**
   * Called right after the aNode's keyword property has changed.
   * 
   * @param aNode
   *        a uri result node
   * @param aNewKeyword
   *        the new keyword
   */
  /* void nodeKeywordChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewKeyword); */
  NS_SCRIPTABLE NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) = 0;

  /**
   * Called right after an annotation of aNode's has changed (set, altered, or
   * unset).
   * 
   * @param aNode
   *        a result node
   * @param aAnnoName
   *        the name of the annotation that changed
   */
  /* void nodeAnnotationChanged (in nsINavHistoryResultNode aNode, in AUTF8String aAnnoName); */
  NS_SCRIPTABLE NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) = 0;

  /**
   * Called right after aNode's dateAdded property has changed.
   *
   * @param aNode
   *        a result node
   * @param aNewValue
   *        the new value of the dateAdded property
   */
  /* void nodeDateAddedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
  NS_SCRIPTABLE NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) = 0;

  /**
   * Called right after aNode's dateModified property has changed.
   *
   * @param aNode
   *        a result node
   * @param aNewValue
   *        the new value of the dateModified property
   */
  /* void nodeLastModifiedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
  NS_SCRIPTABLE NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) = 0;

  /**
   * Called when an item is being replaced with another item at the exact
   * same position.
   *
   * @param aParentNode
   *        the parent node of the node which is being replaced
   * @param aOldNode
   *        the node which is being replaced
   * @param aNewNode
   *        the new node
   * @param aParentNode
   *        the index in aParentNode, at which a node is being replaced
   */
  /* void nodeReplaced (in nsINavHistoryContainerResultNode aParentNode, in nsINavHistoryResultNode aOldNode, in nsINavHistoryResultNode aNewNode, in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD NodeReplaced(nsINavHistoryContainerResultNode *aParentNode, nsINavHistoryResultNode *aOldNode, nsINavHistoryResultNode *aNewNode, PRUint32 aIndex) = 0;

  /**
   * Called after a container node went from closed to opened.
   *
   * @note  This method is DEPRECATED.  In the future only containerStateChanged
   *        will notify when a container is opened.
   *
   * @param aContainerNode
   *        the container node which was opened
   */
  /* void containerOpened (in nsINavHistoryContainerResultNode aContainerNode); */
  NS_SCRIPTABLE NS_IMETHOD ContainerOpened(nsINavHistoryContainerResultNode *aContainerNode) = 0;

  /**
   * Called after a container node went from opened to closed. This will be
   * called for the topmost container that is closing, and implies that any
   * child containers have closed as well.
   *
   * @note  This method is DEPRECATED.  In the future only containerStateChanged
   *        will notify when a container is closed.
   *
   * @param aContainerNode
   *        the container node which was closed
   */
  /* void containerClosed (in nsINavHistoryContainerResultNode aContainerNode); */
  NS_SCRIPTABLE NS_IMETHOD ContainerClosed(nsINavHistoryContainerResultNode *aContainerNode) = 0;

  /**
   * Called after a container changes state.
   *
   * @param aContainerNode
   *        The container that has changed state.
   * @param aOldState
   *        The state that aContainerNode has transitioned out of.
   * @param aNewState
   *        The state that aContainerNode has transitioned into.
   */
  /* void containerStateChanged (in nsINavHistoryContainerResultNode aContainerNode, in unsigned long aOldState, in unsigned long aNewState); */
  NS_SCRIPTABLE NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, PRUint32 aOldState, PRUint32 aNewState) = 0;

  /**
   * Called when something significant has happened within the container. The
   * contents of the container should be re-built.
   *
   * @param aContainerNode
   *        the container node to invalidate
   */
  /* void invalidateContainer (in nsINavHistoryContainerResultNode aContainerNode); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) = 0;

  /**
   * This is called to indicate to the UI that the sort has changed to the
   * given mode. For trees, for example, this would update the column headers
   * to reflect the sorting. For many other types of views, this won't be
   * applicable.
   *
   * @param sortingMode  One of nsINavHistoryQueryOptions.SORT_BY_* that
   *                     indicates the new sorting mode.
   *
   * This only is expected to update the sorting UI. invalidateAll() will also
   * get called if the sorting changes to update everything.
   */
  /* void sortingChanged (in unsigned short sortingMode); */
  NS_SCRIPTABLE NS_IMETHOD SortingChanged(PRUint16 sortingMode) = 0;

  /**
   * This is called to indicate that a batch operation is about to start or end.
   * The observer could want to disable some events or updates during batches,
   * since multiple operations are packed in a short time.
   * For example treeviews could temporarily suppress select notifications.
   *
   * @param aToggleMode
   *        true if a batch is starting, false if it's ending.
   */
  /* void batching (in boolean aToggleMode); */
  NS_SCRIPTABLE NS_IMETHOD Batching(PRBool aToggleMode) = 0;

  /**
   * Called by the result when this observer is added.
   */
  /* attribute nsINavHistoryResult result; */
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsINavHistoryResult **aResult) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetResult(nsINavHistoryResult *aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultObserver, NS_INAVHISTORYRESULTOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, PRUint32 aNewIndex); \
  NS_SCRIPTABLE NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, PRUint32 aOldIndex); \
  NS_SCRIPTABLE NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, PRUint32 aOldIndex, nsINavHistoryContainerResultNode *aNewParent, PRUint32 aNewIndex); \
  NS_SCRIPTABLE NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle); \
  NS_SCRIPTABLE NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI); \
  NS_SCRIPTABLE NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode); \
  NS_SCRIPTABLE NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, PRUint32 aNewAccessCount); \
  NS_SCRIPTABLE NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode); \
  NS_SCRIPTABLE NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword); \
  NS_SCRIPTABLE NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName); \
  NS_SCRIPTABLE NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue); \
  NS_SCRIPTABLE NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue); \
  NS_SCRIPTABLE NS_IMETHOD NodeReplaced(nsINavHistoryContainerResultNode *aParentNode, nsINavHistoryResultNode *aOldNode, nsINavHistoryResultNode *aNewNode, PRUint32 aIndex); \
  NS_SCRIPTABLE NS_IMETHOD ContainerOpened(nsINavHistoryContainerResultNode *aContainerNode); \
  NS_SCRIPTABLE NS_IMETHOD ContainerClosed(nsINavHistoryContainerResultNode *aContainerNode); \
  NS_SCRIPTABLE NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, PRUint32 aOldState, PRUint32 aNewState); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode); \
  NS_SCRIPTABLE NS_IMETHOD SortingChanged(PRUint16 sortingMode); \
  NS_SCRIPTABLE NS_IMETHOD Batching(PRBool aToggleMode); \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsINavHistoryResult **aResult); \
  NS_SCRIPTABLE NS_IMETHOD SetResult(nsINavHistoryResult *aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, PRUint32 aNewIndex) { return _to NodeInserted(aParent, aNode, aNewIndex); } \
  NS_SCRIPTABLE NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, PRUint32 aOldIndex) { return _to NodeRemoved(aParent, aItem, aOldIndex); } \
  NS_SCRIPTABLE NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, PRUint32 aOldIndex, nsINavHistoryContainerResultNode *aNewParent, PRUint32 aNewIndex) { return _to NodeMoved(aNode, aOldParent, aOldIndex, aNewParent, aNewIndex); } \
  NS_SCRIPTABLE NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) { return _to NodeTitleChanged(aNode, aNewTitle); } \
  NS_SCRIPTABLE NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) { return _to NodeURIChanged(aNode, aNewURI); } \
  NS_SCRIPTABLE NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) { return _to NodeIconChanged(aNode); } \
  NS_SCRIPTABLE NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, PRUint32 aNewAccessCount) { return _to NodeHistoryDetailsChanged(aNode, aNewVisitDate, aNewAccessCount); } \
  NS_SCRIPTABLE NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) { return _to NodeTagsChanged(aNode); } \
  NS_SCRIPTABLE NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) { return _to NodeKeywordChanged(aNode, aNewKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) { return _to NodeAnnotationChanged(aNode, aAnnoName); } \
  NS_SCRIPTABLE NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return _to NodeDateAddedChanged(aNode, aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return _to NodeLastModifiedChanged(aNode, aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD NodeReplaced(nsINavHistoryContainerResultNode *aParentNode, nsINavHistoryResultNode *aOldNode, nsINavHistoryResultNode *aNewNode, PRUint32 aIndex) { return _to NodeReplaced(aParentNode, aOldNode, aNewNode, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ContainerOpened(nsINavHistoryContainerResultNode *aContainerNode) { return _to ContainerOpened(aContainerNode); } \
  NS_SCRIPTABLE NS_IMETHOD ContainerClosed(nsINavHistoryContainerResultNode *aContainerNode) { return _to ContainerClosed(aContainerNode); } \
  NS_SCRIPTABLE NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, PRUint32 aOldState, PRUint32 aNewState) { return _to ContainerStateChanged(aContainerNode, aOldState, aNewState); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) { return _to InvalidateContainer(aContainerNode); } \
  NS_SCRIPTABLE NS_IMETHOD SortingChanged(PRUint16 sortingMode) { return _to SortingChanged(sortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD Batching(PRBool aToggleMode) { return _to Batching(aToggleMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsINavHistoryResult **aResult) { return _to GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD SetResult(nsINavHistoryResult *aResult) { return _to SetResult(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, PRUint32 aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeInserted(aParent, aNode, aNewIndex); } \
  NS_SCRIPTABLE NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, PRUint32 aOldIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeRemoved(aParent, aItem, aOldIndex); } \
  NS_SCRIPTABLE NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, PRUint32 aOldIndex, nsINavHistoryContainerResultNode *aNewParent, PRUint32 aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeMoved(aNode, aOldParent, aOldIndex, aNewParent, aNewIndex); } \
  NS_SCRIPTABLE NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeTitleChanged(aNode, aNewTitle); } \
  NS_SCRIPTABLE NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeURIChanged(aNode, aNewURI); } \
  NS_SCRIPTABLE NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeIconChanged(aNode); } \
  NS_SCRIPTABLE NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, PRUint32 aNewAccessCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeHistoryDetailsChanged(aNode, aNewVisitDate, aNewAccessCount); } \
  NS_SCRIPTABLE NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeTagsChanged(aNode); } \
  NS_SCRIPTABLE NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeKeywordChanged(aNode, aNewKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeAnnotationChanged(aNode, aAnnoName); } \
  NS_SCRIPTABLE NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeDateAddedChanged(aNode, aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeLastModifiedChanged(aNode, aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD NodeReplaced(nsINavHistoryContainerResultNode *aParentNode, nsINavHistoryResultNode *aOldNode, nsINavHistoryResultNode *aNewNode, PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeReplaced(aParentNode, aOldNode, aNewNode, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ContainerOpened(nsINavHistoryContainerResultNode *aContainerNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainerOpened(aContainerNode); } \
  NS_SCRIPTABLE NS_IMETHOD ContainerClosed(nsINavHistoryContainerResultNode *aContainerNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainerClosed(aContainerNode); } \
  NS_SCRIPTABLE NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, PRUint32 aOldState, PRUint32 aNewState) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainerStateChanged(aContainerNode, aOldState, aNewState); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateContainer(aContainerNode); } \
  NS_SCRIPTABLE NS_IMETHOD SortingChanged(PRUint16 sortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SortingChanged(sortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD Batching(PRBool aToggleMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Batching(aToggleMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsINavHistoryResult **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD SetResult(nsINavHistoryResult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResult(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultObserver : public nsINavHistoryResultObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTOBSERVER

  nsNavHistoryResultObserver();

private:
  ~nsNavHistoryResultObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResultObserver, nsINavHistoryResultObserver)

nsNavHistoryResultObserver::nsNavHistoryResultObserver()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultObserver::~nsNavHistoryResultObserver()
{
  /* destructor code */
}

/* void nodeInserted (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aNode, in unsigned long aNewIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, PRUint32 aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeRemoved (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aItem, in unsigned long aOldIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, PRUint32 aOldIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeMoved (in nsINavHistoryResultNode aNode, in nsINavHistoryContainerResultNode aOldParent, in unsigned long aOldIndex, in nsINavHistoryContainerResultNode aNewParent, in unsigned long aNewIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, PRUint32 aOldIndex, nsINavHistoryContainerResultNode *aNewParent, PRUint32 aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeTitleChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewTitle); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeURIChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewURI); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeIconChanged (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeIconChanged(nsINavHistoryResultNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeHistoryDetailsChanged (in nsINavHistoryResultNode aNode, in PRTime aNewVisitDate, in unsigned long aNewAccessCount); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, PRUint32 aNewAccessCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeTagsChanged (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeTagsChanged(nsINavHistoryResultNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeKeywordChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewKeyword); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeAnnotationChanged (in nsINavHistoryResultNode aNode, in AUTF8String aAnnoName); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeDateAddedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeLastModifiedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeReplaced (in nsINavHistoryContainerResultNode aParentNode, in nsINavHistoryResultNode aOldNode, in nsINavHistoryResultNode aNewNode, in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeReplaced(nsINavHistoryContainerResultNode *aParentNode, nsINavHistoryResultNode *aOldNode, nsINavHistoryResultNode *aNewNode, PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void containerOpened (in nsINavHistoryContainerResultNode aContainerNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::ContainerOpened(nsINavHistoryContainerResultNode *aContainerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void containerClosed (in nsINavHistoryContainerResultNode aContainerNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::ContainerClosed(nsINavHistoryContainerResultNode *aContainerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void containerStateChanged (in nsINavHistoryContainerResultNode aContainerNode, in unsigned long aOldState, in unsigned long aNewState); */
NS_IMETHODIMP nsNavHistoryResultObserver::ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, PRUint32 aOldState, PRUint32 aNewState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateContainer (in nsINavHistoryContainerResultNode aContainerNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sortingChanged (in unsigned short sortingMode); */
NS_IMETHODIMP nsNavHistoryResultObserver::SortingChanged(PRUint16 sortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void batching (in boolean aToggleMode); */
NS_IMETHODIMP nsNavHistoryResultObserver::Batching(PRBool aToggleMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsINavHistoryResult result; */
NS_IMETHODIMP nsNavHistoryResultObserver::GetResult(nsINavHistoryResult **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResultObserver::SetResult(nsINavHistoryResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResultTreeViewer */
#define NS_INAVHISTORYRESULTTREEVIEWER_IID_STR "f8b518c0-1faf-11df-8a39-0800200c9a66"

#define NS_INAVHISTORYRESULTTREEVIEWER_IID \
  {0xf8b518c0, 0x1faf, 0x11df, \
    { 0x8a, 0x39, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * TODO: Bug 517719.
 *
 * A predefined view adaptor for interfacing results with an nsITree. This
 * object will remove itself from its associated result when the tree has been
 * detached. This prevents circular references. Users should be aware of this,
 * if you want to re-use the same viewer, you will need to keep your own
 * reference to it and re-initialize it when the tree changes. If you use this
 * object, attach it to a result, never attach it to a tree, and forget about
 * it, it will leak!
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryResultTreeViewer : public nsINavHistoryResultObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTTREEVIEWER_IID)

  /**
   * This allows you to get at the real node for a given row index. This is
   * only valid when a tree is attached.
   */
  /* nsINavHistoryResultNode nodeForTreeIndex (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD NodeForTreeIndex(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM) = 0;

  /**
   * Reverse of nodeForFlatIndex, returns the row index for a given result node.
   * Returns INDEX_INVISIBLE if the item is not visible (for example, its
   * parent is collapsed). This is only valid when a tree is attached. The
   * the result will always be INDEX_INVISIBLE if not.
   * 
   * Note: This sounds sort of obvious, but it got me: aNode must be a node
   *       retrieved from the same result that this viewer is for. If you 
   *       execute another query and get a node from a _different_ result, this 
   *       function will always return the index of that node in the tree that
   *       is attached to that result.
   */
  enum { INDEX_INVISIBLE = 4294967295U };

  /* unsigned long treeIndexForNode (in nsINavHistoryResultNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultTreeViewer, NS_INAVHISTORYRESULTTREEVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTTREEVIEWER \
  NS_SCRIPTABLE NS_IMETHOD NodeForTreeIndex(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTTREEVIEWER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NodeForTreeIndex(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return _to NodeForTreeIndex(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM) { return _to TreeIndexForNode(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTTREEVIEWER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NodeForTreeIndex(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeForTreeIndex(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TreeIndexForNode(aNode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultTreeViewer : public nsINavHistoryResultTreeViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTTREEVIEWER

  nsNavHistoryResultTreeViewer();

private:
  ~nsNavHistoryResultTreeViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResultTreeViewer, nsINavHistoryResultTreeViewer)

nsNavHistoryResultTreeViewer::nsNavHistoryResultTreeViewer()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultTreeViewer::~nsNavHistoryResultTreeViewer()
{
  /* destructor code */
}

/* nsINavHistoryResultNode nodeForTreeIndex (in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryResultTreeViewer::NodeForTreeIndex(PRUint32 aIndex, nsINavHistoryResultNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long treeIndexForNode (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultTreeViewer::TreeIndexForNode(nsINavHistoryResultNode *aNode, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResult */
#define NS_INAVHISTORYRESULT_IID_STR "c2229ce3-2159-4001-859c-7013c52f7619"

#define NS_INAVHISTORYRESULT_IID \
  {0xc2229ce3, 0x2159, 0x4001, \
    { 0x85, 0x9c, 0x70, 0x13, 0xc5, 0x2f, 0x76, 0x19 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULT_IID)

  /**
 * The result of a history/bookmark query.
 */
/**
   * Sorts all nodes recursively by the given parameter, one of
   * nsINavHistoryQueryOptions.SORT_BY_*  This will update the corresponding
   * options for this result, so that re-using the current options/queries will
   * always give you the current view.
   */
  /* attribute unsigned short sortingMode; */
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode) = 0;

  /**
   * The annotation to use in SORT_BY_ANNOTATION_* sorting modes, set this
   * before setting the sortingMode attribute.
   */
  /* attribute AUTF8String sortingAnnotation; */
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) = 0;

  /**
   * Whether or not notifications on result changes are suppressed.
   * Initially set to false.
   *
   * Use this to avoid flickering and to improve performance when you
   * do temporary changes to the result structure (e.g. when searching for a
   * node recursively).
   */
  /* attribute boolean suppressNotifications; */
  NS_SCRIPTABLE NS_IMETHOD GetSuppressNotifications(PRBool *aSuppressNotifications) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSuppressNotifications(PRBool aSuppressNotifications) = 0;

  /**
   * Adds an observer for changes done in the result.
   *
   * @param aObserver
   *        a result observer.
   * @param aOwnsWeak
   *        If false, the result will keep an owning reference to the observer,
   *        which must be removed using removeObserver.
   *        If true, the result will keep a weak reference to the observer, which
   *        must implement nsISupportsWeakReference.
   *
   * @see nsINavHistoryResultObserver
   */
  /* void addObserver (in nsINavHistoryResultObserver aObserver, in boolean aOwnsWeak); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, PRBool aOwnsWeak) = 0;

  /**
   * Removes an observer that was added by addObserver.
   *
   * @param aObserver
   *        a result observer that was added by addObserver.
   */
  /* void removeObserver (in nsINavHistoryResultObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) = 0;

  /**
   * This is the root of the results. Remember that you need to open all
   * containers for their contents to be valid.
   *
   * When a result goes out of scope it will continue to observe changes till
   * it is cycle collected.  While the result waits to be collected it will stay
   * in memory, and continue to update itself, potentially causing unwanted
   * additional work.  When you close the root node the result will stop
   * observing changes, so it is good practice to close the root node when you
   * are done with a result, since that will avoid unwanted performance hits.
   */
  /* readonly attribute nsINavHistoryContainerResultNode root; */
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode **aRoot) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResult, NS_INAVHISTORYRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULT \
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode); \
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode); \
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD GetSuppressNotifications(PRBool *aSuppressNotifications); \
  NS_SCRIPTABLE NS_IMETHOD SetSuppressNotifications(PRBool aSuppressNotifications); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, PRBool aOwnsWeak); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode **aRoot); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode) { return _to GetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode) { return _to SetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return _to GetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return _to SetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuppressNotifications(PRBool *aSuppressNotifications) { return _to GetSuppressNotifications(aSuppressNotifications); } \
  NS_SCRIPTABLE NS_IMETHOD SetSuppressNotifications(PRBool aSuppressNotifications) { return _to SetSuppressNotifications(aSuppressNotifications); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, PRBool aOwnsWeak) { return _to AddObserver(aObserver, aOwnsWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode **aRoot) { return _to GetRoot(aRoot); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuppressNotifications(PRBool *aSuppressNotifications) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuppressNotifications(aSuppressNotifications); } \
  NS_SCRIPTABLE NS_IMETHOD SetSuppressNotifications(PRBool aSuppressNotifications) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuppressNotifications(aSuppressNotifications); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, PRBool aOwnsWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver, aOwnsWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode **aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResult : public nsINavHistoryResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULT

  nsNavHistoryResult();

private:
  ~nsNavHistoryResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryResult, nsINavHistoryResult)

nsNavHistoryResult::nsNavHistoryResult()
{
  /* member initializers and constructor code */
}

nsNavHistoryResult::~nsNavHistoryResult()
{
  /* destructor code */
}

/* attribute unsigned short sortingMode; */
NS_IMETHODIMP nsNavHistoryResult::GetSortingMode(PRUint16 *aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSortingMode(PRUint16 aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String sortingAnnotation; */
NS_IMETHODIMP nsNavHistoryResult::GetSortingAnnotation(nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSortingAnnotation(const nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean suppressNotifications; */
NS_IMETHODIMP nsNavHistoryResult::GetSuppressNotifications(PRBool *aSuppressNotifications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSuppressNotifications(PRBool aSuppressNotifications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavHistoryResultObserver aObserver, in boolean aOwnsWeak); */
NS_IMETHODIMP nsNavHistoryResult::AddObserver(nsINavHistoryResultObserver *aObserver, PRBool aOwnsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavHistoryResultObserver aObserver); */
NS_IMETHODIMP nsNavHistoryResult::RemoveObserver(nsINavHistoryResultObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryContainerResultNode root; */
NS_IMETHODIMP nsNavHistoryResult::GetRoot(nsINavHistoryContainerResultNode **aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryObserver */
#define NS_INAVHISTORYOBSERVER_IID_STR "0a5ce210-c803-11de-8a39-0800200c9a66"

#define NS_INAVHISTORYOBSERVER_IID \
  {0x0a5ce210, 0xc803, 0x11de, \
    { 0x8a, 0x39, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Similar to nsIRDFObserver for history. Note that we don't pass the data
 * source since that is always the global history.
 *
 * DANGER! If you are in the middle of a batch transaction, there may be a
 * database transaction active. You can still access the DB, but be careful.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYOBSERVER_IID)

  /**
   * Notifies you that a bunch of things are about to change, don't do any
   * heavy-duty processing until onEndUpdateBatch is called.
   */
  /* void onBeginUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void) = 0;

  /**
   * Notifies you that we are done doing a bunch of things and you should go
   * ahead and update UI, etc.
   */
  /* void onEndUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void) = 0;

  /**
   * Called when a resource is visited. This is called the first time a
   * resource (page, image, etc.) is seen as well as every subsequent time.
   *
   * Normally, transition types of TRANSITION_EMBED (corresponding to images in
   * a page, for example) are not displayed in history results (unless
   * includeHidden is set). Many observers can ignore _EMBED notifications
   * (which will comprise the majority of visit notifications) to save work.
   *
   * @param aVisitID        ID of the visit that was just created.
   * @param aTime           Time of the visit
   * @param aSessionID      The ID of one connected sequence of visits.
   * @param aReferringID    The ID of the visit the user came from. 0 if empty.
   * @param aTransitionType One of nsINavHistory.TRANSITION_*
   * @param aAdded          Incremented by query nodes when the visited uri
   *                        belongs to them. If no such query exists, the 
   *                        history result creates a new query node dynamically.
   *                        It is used in places views only and can be ignored.
   */
  /* void onVisit (in nsIURI aURI, in long long aVisitID, in PRTime aTime, in long long aSessionID, in long long aReferringID, in unsigned long aTransitionType, out unsigned long aAdded); */
  NS_SCRIPTABLE NS_IMETHOD OnVisit(nsIURI *aURI, PRInt64 aVisitID, PRTime aTime, PRInt64 aSessionID, PRInt64 aReferringID, PRUint32 aTransitionType, PRUint32 *aAdded NS_OUTPARAM) = 0;

  /**
   * Called whenever either the "real" title or the custom title of the page
   * changed. BOTH TITLES ARE ALWAYS INCLUDED in this notification, even though
   * only one will change at a time. Often, consumers will want to display the
   * user title if it is available, and fall back to the page title (the one
   * specified in the <title> tag of the page).
   *
   * Note that there is a difference between an empty title and a NULL title.
   * An empty string means that somebody specifically set the title to be
   * nothing. NULL means nobody set it. From C++: use IsVoid() and SetIsVoid()
   * to see whether an empty string is "null" or not (it will always be an
   * empty string in either case).
   *
   */
  /* void onTitleChanged (in nsIURI aURI, in AString aPageTitle); */
  NS_SCRIPTABLE NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle) = 0;

  /**
   * This page and all of its visits are about to be deleted.  Note: the page
   * may not necessarily have actually existed for this function to be called.
   *
   * @param aURI
   *        The URI being deleted.
   */
  /* void onBeforeDeleteURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD OnBeforeDeleteURI(nsIURI *aURI) = 0;

  /**
   * This page and all of its visits are being deleted. Note: the page may not
   * necessarily have actually existed for this function to be called.
   *
   * Delete notifications are only 99.99% accurate. Batch delete operations
   * must be done in two steps, so first come notifications, then a bulk
   * delete. If there is some error in the middle (for example, out of memory)
   * then you'll get a notification and it won't get deleted. There's no easy
   * way around this.
   */
  /* void onDeleteURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD OnDeleteURI(nsIURI *aURI) = 0;

  /**
   * Notification that all of history is being deleted.
   */
  /* void onClearHistory (); */
  NS_SCRIPTABLE NS_IMETHOD OnClearHistory(void) = 0;

  /**
   * A page has had some attribute on it changed. Note that for TYPED and
   * HIDDEN, the page may not necessarily have been added yet.
   */
  enum { ATTRIBUTE_FAVICON = 3U };

  /* void onPageChanged (in nsIURI aURI, in unsigned long aWhat, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD OnPageChanged(nsIURI *aURI, PRUint32 aWhat, const nsAString & aValue) = 0;

  /**
   * Called when some visits of an history entry are expired.
   *
   * @param aURI
   *        The page whose visits have been expired.
   * @param aVisitTime
   *        The largest visit time in microseconds that has been expired.  We
   *        guarantee that we don't have any visit older than this date.
   *
   * @note: when all visits for a page are expired and also the full page entry
   *        is expired, you will only get an onDeleteURI notification.  If a
   *        page entry is removed, then you can be sure that we don't have
   *        anymore visits for it.
   */
  /* void onDeleteVisits (in nsIURI aURI, in PRTime aVisitTime); */
  NS_SCRIPTABLE NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryObserver, NS_INAVHISTORYOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD OnVisit(nsIURI *aURI, PRInt64 aVisitID, PRTime aTime, PRInt64 aSessionID, PRInt64 aReferringID, PRUint32 aTransitionType, PRUint32 *aAdded NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle); \
  NS_SCRIPTABLE NS_IMETHOD OnBeforeDeleteURI(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD OnDeleteURI(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD OnClearHistory(void); \
  NS_SCRIPTABLE NS_IMETHOD OnPageChanged(nsIURI *aURI, PRUint32 aWhat, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void) { return _to OnBeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void) { return _to OnEndUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnVisit(nsIURI *aURI, PRInt64 aVisitID, PRTime aTime, PRInt64 aSessionID, PRInt64 aReferringID, PRUint32 aTransitionType, PRUint32 *aAdded NS_OUTPARAM) { return _to OnVisit(aURI, aVisitID, aTime, aSessionID, aReferringID, aTransitionType, aAdded); } \
  NS_SCRIPTABLE NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle) { return _to OnTitleChanged(aURI, aPageTitle); } \
  NS_SCRIPTABLE NS_IMETHOD OnBeforeDeleteURI(nsIURI *aURI) { return _to OnBeforeDeleteURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD OnDeleteURI(nsIURI *aURI) { return _to OnDeleteURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD OnClearHistory(void) { return _to OnClearHistory(); } \
  NS_SCRIPTABLE NS_IMETHOD OnPageChanged(nsIURI *aURI, PRUint32 aWhat, const nsAString & aValue) { return _to OnPageChanged(aURI, aWhat, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime) { return _to OnDeleteVisits(aURI, aVisitTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnVisit(nsIURI *aURI, PRInt64 aVisitID, PRTime aTime, PRInt64 aSessionID, PRInt64 aReferringID, PRUint32 aTransitionType, PRUint32 *aAdded NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnVisit(aURI, aVisitID, aTime, aSessionID, aReferringID, aTransitionType, aAdded); } \
  NS_SCRIPTABLE NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTitleChanged(aURI, aPageTitle); } \
  NS_SCRIPTABLE NS_IMETHOD OnBeforeDeleteURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeforeDeleteURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD OnDeleteURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDeleteURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD OnClearHistory(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClearHistory(); } \
  NS_SCRIPTABLE NS_IMETHOD OnPageChanged(nsIURI *aURI, PRUint32 aWhat, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageChanged(aURI, aWhat, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDeleteVisits(aURI, aVisitTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryObserver : public nsINavHistoryObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYOBSERVER

  nsNavHistoryObserver();

private:
  ~nsNavHistoryObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryObserver, nsINavHistoryObserver)

nsNavHistoryObserver::nsNavHistoryObserver()
{
  /* member initializers and constructor code */
}

nsNavHistoryObserver::~nsNavHistoryObserver()
{
  /* destructor code */
}

/* void onBeginUpdateBatch (); */
NS_IMETHODIMP nsNavHistoryObserver::OnBeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndUpdateBatch (); */
NS_IMETHODIMP nsNavHistoryObserver::OnEndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onVisit (in nsIURI aURI, in long long aVisitID, in PRTime aTime, in long long aSessionID, in long long aReferringID, in unsigned long aTransitionType, out unsigned long aAdded); */
NS_IMETHODIMP nsNavHistoryObserver::OnVisit(nsIURI *aURI, PRInt64 aVisitID, PRTime aTime, PRInt64 aSessionID, PRInt64 aReferringID, PRUint32 aTransitionType, PRUint32 *aAdded NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onTitleChanged (in nsIURI aURI, in AString aPageTitle); */
NS_IMETHODIMP nsNavHistoryObserver::OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onBeforeDeleteURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryObserver::OnBeforeDeleteURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDeleteURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryObserver::OnDeleteURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onClearHistory (); */
NS_IMETHODIMP nsNavHistoryObserver::OnClearHistory()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPageChanged (in nsIURI aURI, in unsigned long aWhat, in AString aValue); */
NS_IMETHODIMP nsNavHistoryObserver::OnPageChanged(nsIURI *aURI, PRUint32 aWhat, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDeleteVisits (in nsIURI aURI, in PRTime aVisitTime); */
NS_IMETHODIMP nsNavHistoryObserver::OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQuery */
#define NS_INAVHISTORYQUERY_IID_STR "dc87ae79-22f1-4dcf-975b-852b01d210cb"

#define NS_INAVHISTORYQUERY_IID \
  {0xdc87ae79, 0x22f1, 0x4dcf, \
    { 0x97, 0x5b, 0x85, 0x2b, 0x01, 0xd2, 0x10, 0xcb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryQuery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERY_IID)

  /**
 * This object encapsulates all the query parameters you're likely to need
 * when building up history UI. All parameters are ANDed together.
 *
 * This is not intended to be a super-general query mechanism. This was designed
 * so that most queries can be done in only one SQL query. This is important
 * because, if the user has their profile on a networked drive, query latency
 * can be non-negligible.
 */
/**
   * Time range for results (INCLUSIVE). The *TimeReference is one of the
   * constants TIME_RELATIVE_* which indicates how to interpret the
   * corresponding time value.
   *   TIME_RELATIVE_EPOCH (default):
   *     The time is relative to Jan 1 1970 GMT, (this is a normal PRTime)
   *   TIME_RELATIVE_TODAY:
   *     The time is relative to this morning at midnight. Normally used for
   *     queries relative to today. For example, a "past week" query would be
   *     today-6 days -> today+1 day
   *   TIME_RELATIVE_NOW:
   *     The time is relative to right now.
   *
   * Note: PRTime is in MICROseconds since 1 Jan 1970. Javascript date objects
   * are expressed in MILLIseconds since 1 Jan 1970.
   *
   * As a special case, a 0 time relative to TIME_RELATIVE_EPOCH indicates that
   * the time is not part of the query. This is the default, so an empty query
   * will match any time. The has* functions return whether the corresponding
   * time is considered.
   *
   * You can read absolute*Time to get the time value that the currently loaded
   * reference points + offset resolve to.
   */
  enum { TIME_RELATIVE_EPOCH = 0U };

  enum { TIME_RELATIVE_TODAY = 1U };

  enum { TIME_RELATIVE_NOW = 2U };

  /* attribute PRTime beginTime; */
  NS_SCRIPTABLE NS_IMETHOD GetBeginTime(PRTime *aBeginTime) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBeginTime(PRTime aBeginTime) = 0;

  /* attribute unsigned long beginTimeReference; */
  NS_SCRIPTABLE NS_IMETHOD GetBeginTimeReference(PRUint32 *aBeginTimeReference) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBeginTimeReference(PRUint32 aBeginTimeReference) = 0;

  /* readonly attribute boolean hasBeginTime; */
  NS_SCRIPTABLE NS_IMETHOD GetHasBeginTime(PRBool *aHasBeginTime) = 0;

  /* readonly attribute PRTime absoluteBeginTime; */
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) = 0;

  /* attribute PRTime endTime; */
  NS_SCRIPTABLE NS_IMETHOD GetEndTime(PRTime *aEndTime) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEndTime(PRTime aEndTime) = 0;

  /* attribute unsigned long endTimeReference; */
  NS_SCRIPTABLE NS_IMETHOD GetEndTimeReference(PRUint32 *aEndTimeReference) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEndTimeReference(PRUint32 aEndTimeReference) = 0;

  /* readonly attribute boolean hasEndTime; */
  NS_SCRIPTABLE NS_IMETHOD GetHasEndTime(PRBool *aHasEndTime) = 0;

  /* readonly attribute PRTime absoluteEndTime; */
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) = 0;

  /**
   * Text search terms.
   */
  /* attribute AString searchTerms; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) = 0;

  /* readonly attribute boolean hasSearchTerms; */
  NS_SCRIPTABLE NS_IMETHOD GetHasSearchTerms(PRBool *aHasSearchTerms) = 0;

  /**
   * Set lower or upper limits for how many times an item has been
   * visited.  The default is -1, and in that case all items are
   * matched regardless of their visit count.
   */
  /* attribute long minVisits; */
  NS_SCRIPTABLE NS_IMETHOD GetMinVisits(PRInt32 *aMinVisits) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMinVisits(PRInt32 aMinVisits) = 0;

  /* attribute long maxVisits; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxVisits(PRInt32 *aMaxVisits) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaxVisits(PRInt32 aMaxVisits) = 0;

  /**
   * When the set of transitions is nonempty, results are limited to pages which
   * have at least one visit for each of the transition types.
   * @note: For searching on more than one transition this can be very slow.
   *
   * Limit results to the specified list of transition types.
   */
  /* void setTransitions ([array, size_is (count), const] in unsigned long transitions, in unsigned long count); */
  NS_SCRIPTABLE NS_IMETHOD SetTransitions(const PRUint32 *transitions, PRUint32 count) = 0;

  /**
   * Get the transitions set for this query.
   */
  /* void getTransitions ([optional] out unsigned long count, [array, size_is (count), retval] out unsigned long transitions); */
  NS_SCRIPTABLE NS_IMETHOD GetTransitions(PRUint32 *count NS_OUTPARAM, PRUint32 **transitions NS_OUTPARAM) = 0;

  /**
   * Get the count of the set query transitions.
   */
  /* readonly attribute unsigned long transitionCount; */
  NS_SCRIPTABLE NS_IMETHOD GetTransitionCount(PRUint32 *aTransitionCount) = 0;

  /**
   * When set, returns only bookmarked items, when unset, returns anything. Setting this
   * is equivalent to listing all bookmark folders in the 'folders' parameter.
   */
  /* attribute boolean onlyBookmarked; */
  NS_SCRIPTABLE NS_IMETHOD GetOnlyBookmarked(PRBool *aOnlyBookmarked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnlyBookmarked(PRBool aOnlyBookmarked) = 0;

  /**
   * This controls the meaning of 'domain', and whether it is an exact match
   * 'domainIsHost' = true, or hierarchical (= false).
   */
  /* attribute boolean domainIsHost; */
  NS_SCRIPTABLE NS_IMETHOD GetDomainIsHost(PRBool *aDomainIsHost) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDomainIsHost(PRBool aDomainIsHost) = 0;

  /**
   * This is the host or domain name (controlled by domainIsHost). When
   * domainIsHost, domain only does exact matching on host names. Otherwise,
   * it will return anything whose host name ends in 'domain'.
   *
   * This one is a little different than most. Setting it to an empty string
   * is a real query and will match any URI that has no host name (local files
   * and such). Set this to NULL (in C++ use SetIsVoid) if you don't want
   * domain matching.
   */
  /* attribute AUTF8String domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsACString & aDomain) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsACString & aDomain) = 0;

  /* readonly attribute boolean hasDomain; */
  NS_SCRIPTABLE NS_IMETHOD GetHasDomain(PRBool *aHasDomain) = 0;

  /**
   * Controls the interpretation of 'uri'. When unset (default), the URI will
   * request an exact match of the specified URI. When set, any history entry
   * beginning in 'uri' will match. For example "http://bar.com/foo" will match
   * "http://bar.com/foo" as well as "http://bar.com/foo/baz.gif".
   */
  /* attribute boolean uriIsPrefix; */
  NS_SCRIPTABLE NS_IMETHOD GetUriIsPrefix(PRBool *aUriIsPrefix) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUriIsPrefix(PRBool aUriIsPrefix) = 0;

  /**
   * This is a URI to match, to, for example, find out every time you visited
   * a given URI. Use uriIsPrefix to control whether this is an exact match.
   */
  /* attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /* readonly attribute boolean hasUri; */
  NS_SCRIPTABLE NS_IMETHOD GetHasUri(PRBool *aHasUri) = 0;

  /**
   * Test for existence or non-existence of a given annotation. We don't
   * currently support >1 annotation name per query. If 'annotationIsNot' is
   * true, we test for the non-existence of the specified annotation.
   *
   * Testing for not annotation will do the same thing as a normal query and
   * remove everything that doesn't have that annotation. Asking for things
   * that DO have a given annotation is a little different. It also includes
   * things that have never been visited. This allows place queries to be
   * returned as well as anything else that may have been tagged with an
   * annotation. This will only work for RESULTS_AS_URI since there will be
   * no visits for these items.
   */
  /* attribute boolean annotationIsNot; */
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationIsNot(PRBool *aAnnotationIsNot) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAnnotationIsNot(PRBool aAnnotationIsNot) = 0;

  /* attribute AUTF8String annotation; */
  NS_SCRIPTABLE NS_IMETHOD GetAnnotation(nsACString & aAnnotation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) = 0;

  /* readonly attribute boolean hasAnnotation; */
  NS_SCRIPTABLE NS_IMETHOD GetHasAnnotation(PRBool *aHasAnnotation) = 0;

  /**
   * Limit results to items that are tagged with all of the given tags.  This
   * attribute must be set to an array of strings.  When called as a getter it
   * will return an array of strings sorted ascending in lexicographical order.
   * The array may be empty in either case.  Duplicate tags may be specified
   * when setting the attribute, but the getter returns only unique tags.
   *
   * To search for items that are tagged with any given tags rather than all,
   * multiple queries may be passed to nsINavHistoryService.executeQueries().
   */
  /* attribute nsIVariant tags; */
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsIVariant **aTags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTags(nsIVariant *aTags) = 0;

  /**
   * If 'tagsAreNot' is true, the results are instead limited to items that
   * are not tagged with any of the given tags.  This attribute is used in
   * conjunction with the 'tags' attribute.
   */
  /* attribute boolean tagsAreNot; */
  NS_SCRIPTABLE NS_IMETHOD GetTagsAreNot(PRBool *aTagsAreNot) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTagsAreNot(PRBool aTagsAreNot) = 0;

  /**
   * Limit results to items that are in all of the given folders.
   */
  /* void getFolders ([optional] out unsigned long count, [array, size_is (count), retval] out long long folders); */
  NS_SCRIPTABLE NS_IMETHOD GetFolders(PRUint32 *count NS_OUTPARAM, PRInt64 **folders NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long folderCount; */
  NS_SCRIPTABLE NS_IMETHOD GetFolderCount(PRUint32 *aFolderCount) = 0;

  /**
   * For the special result type RESULTS_AS_TAG_CONTENTS we can define only
   * one folder that must be a tag folder. This is not recursive so results
   * will be returned from the first level of that folder.
   */
  /* void setFolders ([array, size_is (folderCount), const] in long long folders, in unsigned long folderCount); */
  NS_SCRIPTABLE NS_IMETHOD SetFolders(const PRInt64 *folders, PRUint32 folderCount) = 0;

  /**
   * Creates a new query item with the same parameters of this one.
   */
  /* nsINavHistoryQuery clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQuery **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQuery, NS_INAVHISTORYQUERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERY \
  NS_SCRIPTABLE NS_IMETHOD GetBeginTime(PRTime *aBeginTime); \
  NS_SCRIPTABLE NS_IMETHOD SetBeginTime(PRTime aBeginTime); \
  NS_SCRIPTABLE NS_IMETHOD GetBeginTimeReference(PRUint32 *aBeginTimeReference); \
  NS_SCRIPTABLE NS_IMETHOD SetBeginTimeReference(PRUint32 aBeginTimeReference); \
  NS_SCRIPTABLE NS_IMETHOD GetHasBeginTime(PRBool *aHasBeginTime); \
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime); \
  NS_SCRIPTABLE NS_IMETHOD GetEndTime(PRTime *aEndTime); \
  NS_SCRIPTABLE NS_IMETHOD SetEndTime(PRTime aEndTime); \
  NS_SCRIPTABLE NS_IMETHOD GetEndTimeReference(PRUint32 *aEndTimeReference); \
  NS_SCRIPTABLE NS_IMETHOD SetEndTimeReference(PRUint32 aEndTimeReference); \
  NS_SCRIPTABLE NS_IMETHOD GetHasEndTime(PRBool *aHasEndTime); \
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime); \
  NS_SCRIPTABLE NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms); \
  NS_SCRIPTABLE NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms); \
  NS_SCRIPTABLE NS_IMETHOD GetHasSearchTerms(PRBool *aHasSearchTerms); \
  NS_SCRIPTABLE NS_IMETHOD GetMinVisits(PRInt32 *aMinVisits); \
  NS_SCRIPTABLE NS_IMETHOD SetMinVisits(PRInt32 aMinVisits); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxVisits(PRInt32 *aMaxVisits); \
  NS_SCRIPTABLE NS_IMETHOD SetMaxVisits(PRInt32 aMaxVisits); \
  NS_SCRIPTABLE NS_IMETHOD SetTransitions(const PRUint32 *transitions, PRUint32 count); \
  NS_SCRIPTABLE NS_IMETHOD GetTransitions(PRUint32 *count NS_OUTPARAM, PRUint32 **transitions NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionCount(PRUint32 *aTransitionCount); \
  NS_SCRIPTABLE NS_IMETHOD GetOnlyBookmarked(PRBool *aOnlyBookmarked); \
  NS_SCRIPTABLE NS_IMETHOD SetOnlyBookmarked(PRBool aOnlyBookmarked); \
  NS_SCRIPTABLE NS_IMETHOD GetDomainIsHost(PRBool *aDomainIsHost); \
  NS_SCRIPTABLE NS_IMETHOD SetDomainIsHost(PRBool aDomainIsHost); \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsACString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsACString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD GetHasDomain(PRBool *aHasDomain); \
  NS_SCRIPTABLE NS_IMETHOD GetUriIsPrefix(PRBool *aUriIsPrefix); \
  NS_SCRIPTABLE NS_IMETHOD SetUriIsPrefix(PRBool aUriIsPrefix); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri); \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetHasUri(PRBool *aHasUri); \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationIsNot(PRBool *aAnnotationIsNot); \
  NS_SCRIPTABLE NS_IMETHOD SetAnnotationIsNot(PRBool aAnnotationIsNot); \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotation(nsACString & aAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD SetAnnotation(const nsACString & aAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD GetHasAnnotation(PRBool *aHasAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsIVariant **aTags); \
  NS_SCRIPTABLE NS_IMETHOD SetTags(nsIVariant *aTags); \
  NS_SCRIPTABLE NS_IMETHOD GetTagsAreNot(PRBool *aTagsAreNot); \
  NS_SCRIPTABLE NS_IMETHOD SetTagsAreNot(PRBool aTagsAreNot); \
  NS_SCRIPTABLE NS_IMETHOD GetFolders(PRUint32 *count NS_OUTPARAM, PRInt64 **folders NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFolderCount(PRUint32 *aFolderCount); \
  NS_SCRIPTABLE NS_IMETHOD SetFolders(const PRInt64 *folders, PRUint32 folderCount); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQuery **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBeginTime(PRTime *aBeginTime) { return _to GetBeginTime(aBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD SetBeginTime(PRTime aBeginTime) { return _to SetBeginTime(aBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetBeginTimeReference(PRUint32 *aBeginTimeReference) { return _to GetBeginTimeReference(aBeginTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD SetBeginTimeReference(PRUint32 aBeginTimeReference) { return _to SetBeginTimeReference(aBeginTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasBeginTime(PRBool *aHasBeginTime) { return _to GetHasBeginTime(aHasBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) { return _to GetAbsoluteBeginTime(aAbsoluteBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndTime(PRTime *aEndTime) { return _to GetEndTime(aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndTime(PRTime aEndTime) { return _to SetEndTime(aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndTimeReference(PRUint32 *aEndTimeReference) { return _to GetEndTimeReference(aEndTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndTimeReference(PRUint32 aEndTimeReference) { return _to SetEndTimeReference(aEndTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasEndTime(PRBool *aHasEndTime) { return _to GetHasEndTime(aHasEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) { return _to GetAbsoluteEndTime(aAbsoluteEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) { return _to GetSearchTerms(aSearchTerms); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) { return _to SetSearchTerms(aSearchTerms); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasSearchTerms(PRBool *aHasSearchTerms) { return _to GetHasSearchTerms(aHasSearchTerms); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinVisits(PRInt32 *aMinVisits) { return _to GetMinVisits(aMinVisits); } \
  NS_SCRIPTABLE NS_IMETHOD SetMinVisits(PRInt32 aMinVisits) { return _to SetMinVisits(aMinVisits); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxVisits(PRInt32 *aMaxVisits) { return _to GetMaxVisits(aMaxVisits); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxVisits(PRInt32 aMaxVisits) { return _to SetMaxVisits(aMaxVisits); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransitions(const PRUint32 *transitions, PRUint32 count) { return _to SetTransitions(transitions, count); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitions(PRUint32 *count NS_OUTPARAM, PRUint32 **transitions NS_OUTPARAM) { return _to GetTransitions(count, transitions); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionCount(PRUint32 *aTransitionCount) { return _to GetTransitionCount(aTransitionCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnlyBookmarked(PRBool *aOnlyBookmarked) { return _to GetOnlyBookmarked(aOnlyBookmarked); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnlyBookmarked(PRBool aOnlyBookmarked) { return _to SetOnlyBookmarked(aOnlyBookmarked); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomainIsHost(PRBool *aDomainIsHost) { return _to GetDomainIsHost(aDomainIsHost); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomainIsHost(PRBool aDomainIsHost) { return _to SetDomainIsHost(aDomainIsHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsACString & aDomain) { return _to GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsACString & aDomain) { return _to SetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasDomain(PRBool *aHasDomain) { return _to GetHasDomain(aHasDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetUriIsPrefix(PRBool *aUriIsPrefix) { return _to GetUriIsPrefix(aUriIsPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD SetUriIsPrefix(PRBool aUriIsPrefix) { return _to SetUriIsPrefix(aUriIsPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasUri(PRBool *aHasUri) { return _to GetHasUri(aHasUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationIsNot(PRBool *aAnnotationIsNot) { return _to GetAnnotationIsNot(aAnnotationIsNot); } \
  NS_SCRIPTABLE NS_IMETHOD SetAnnotationIsNot(PRBool aAnnotationIsNot) { return _to SetAnnotationIsNot(aAnnotationIsNot); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotation(nsACString & aAnnotation) { return _to GetAnnotation(aAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) { return _to SetAnnotation(aAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasAnnotation(PRBool *aHasAnnotation) { return _to GetHasAnnotation(aHasAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsIVariant **aTags) { return _to GetTags(aTags); } \
  NS_SCRIPTABLE NS_IMETHOD SetTags(nsIVariant *aTags) { return _to SetTags(aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetTagsAreNot(PRBool *aTagsAreNot) { return _to GetTagsAreNot(aTagsAreNot); } \
  NS_SCRIPTABLE NS_IMETHOD SetTagsAreNot(PRBool aTagsAreNot) { return _to SetTagsAreNot(aTagsAreNot); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolders(PRUint32 *count NS_OUTPARAM, PRInt64 **folders NS_OUTPARAM) { return _to GetFolders(count, folders); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderCount(PRUint32 *aFolderCount) { return _to GetFolderCount(aFolderCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetFolders(const PRInt64 *folders, PRUint32 folderCount) { return _to SetFolders(folders, folderCount); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQuery **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBeginTime(PRTime *aBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeginTime(aBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD SetBeginTime(PRTime aBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBeginTime(aBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetBeginTimeReference(PRUint32 *aBeginTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeginTimeReference(aBeginTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD SetBeginTimeReference(PRUint32 aBeginTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBeginTimeReference(aBeginTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasBeginTime(PRBool *aHasBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasBeginTime(aHasBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsoluteBeginTime(aAbsoluteBeginTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndTime(PRTime *aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndTime(aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndTime(PRTime aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndTime(aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndTimeReference(PRUint32 *aEndTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndTimeReference(aEndTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD SetEndTimeReference(PRUint32 aEndTimeReference) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndTimeReference(aEndTimeReference); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasEndTime(PRBool *aHasEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEndTime(aHasEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsoluteEndTime(aAbsoluteEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchTerms(aSearchTerms); } \
  NS_SCRIPTABLE NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchTerms(aSearchTerms); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasSearchTerms(PRBool *aHasSearchTerms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasSearchTerms(aHasSearchTerms); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinVisits(PRInt32 *aMinVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinVisits(aMinVisits); } \
  NS_SCRIPTABLE NS_IMETHOD SetMinVisits(PRInt32 aMinVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinVisits(aMinVisits); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxVisits(PRInt32 *aMaxVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxVisits(aMaxVisits); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxVisits(PRInt32 aMaxVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxVisits(aMaxVisits); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransitions(const PRUint32 *transitions, PRUint32 count) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransitions(transitions, count); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitions(PRUint32 *count NS_OUTPARAM, PRUint32 **transitions NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitions(count, transitions); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionCount(PRUint32 *aTransitionCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitionCount(aTransitionCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnlyBookmarked(PRBool *aOnlyBookmarked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlyBookmarked(aOnlyBookmarked); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnlyBookmarked(PRBool aOnlyBookmarked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlyBookmarked(aOnlyBookmarked); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomainIsHost(PRBool *aDomainIsHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainIsHost(aDomainIsHost); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomainIsHost(PRBool aDomainIsHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomainIsHost(aDomainIsHost); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsACString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD SetDomain(const nsACString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasDomain(PRBool *aHasDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasDomain(aHasDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetUriIsPrefix(PRBool *aUriIsPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriIsPrefix(aUriIsPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD SetUriIsPrefix(PRBool aUriIsPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUriIsPrefix(aUriIsPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasUri(PRBool *aHasUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasUri(aHasUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationIsNot(PRBool *aAnnotationIsNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationIsNot(aAnnotationIsNot); } \
  NS_SCRIPTABLE NS_IMETHOD SetAnnotationIsNot(PRBool aAnnotationIsNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnnotationIsNot(aAnnotationIsNot); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotation(nsACString & aAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotation(aAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnnotation(aAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasAnnotation(PRBool *aHasAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasAnnotation(aHasAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetTags(nsIVariant **aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } \
  NS_SCRIPTABLE NS_IMETHOD SetTags(nsIVariant *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTags(aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetTagsAreNot(PRBool *aTagsAreNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsAreNot(aTagsAreNot); } \
  NS_SCRIPTABLE NS_IMETHOD SetTagsAreNot(PRBool aTagsAreNot) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTagsAreNot(aTagsAreNot); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolders(PRUint32 *count NS_OUTPARAM, PRInt64 **folders NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolders(count, folders); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderCount(PRUint32 *aFolderCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderCount(aFolderCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetFolders(const PRInt64 *folders, PRUint32 folderCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFolders(folders, folderCount); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQuery **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQuery : public nsINavHistoryQuery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERY

  nsNavHistoryQuery();

private:
  ~nsNavHistoryQuery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryQuery, nsINavHistoryQuery)

nsNavHistoryQuery::nsNavHistoryQuery()
{
  /* member initializers and constructor code */
}

nsNavHistoryQuery::~nsNavHistoryQuery()
{
  /* destructor code */
}

/* attribute PRTime beginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetBeginTime(PRTime *aBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetBeginTime(PRTime aBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long beginTimeReference; */
NS_IMETHODIMP nsNavHistoryQuery::GetBeginTimeReference(PRUint32 *aBeginTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetBeginTimeReference(PRUint32 aBeginTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasBeginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasBeginTime(PRBool *aHasBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime absoluteBeginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRTime endTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetEndTime(PRTime *aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetEndTime(PRTime aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long endTimeReference; */
NS_IMETHODIMP nsNavHistoryQuery::GetEndTimeReference(PRUint32 *aEndTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetEndTimeReference(PRUint32 aEndTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasEndTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasEndTime(PRBool *aHasEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime absoluteEndTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetAbsoluteEndTime(PRTime *aAbsoluteEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString searchTerms; */
NS_IMETHODIMP nsNavHistoryQuery::GetSearchTerms(nsAString & aSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetSearchTerms(const nsAString & aSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasSearchTerms; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasSearchTerms(PRBool *aHasSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long minVisits; */
NS_IMETHODIMP nsNavHistoryQuery::GetMinVisits(PRInt32 *aMinVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetMinVisits(PRInt32 aMinVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxVisits; */
NS_IMETHODIMP nsNavHistoryQuery::GetMaxVisits(PRInt32 *aMaxVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetMaxVisits(PRInt32 aMaxVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTransitions ([array, size_is (count), const] in unsigned long transitions, in unsigned long count); */
NS_IMETHODIMP nsNavHistoryQuery::SetTransitions(const PRUint32 *transitions, PRUint32 count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTransitions ([optional] out unsigned long count, [array, size_is (count), retval] out unsigned long transitions); */
NS_IMETHODIMP nsNavHistoryQuery::GetTransitions(PRUint32 *count NS_OUTPARAM, PRUint32 **transitions NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long transitionCount; */
NS_IMETHODIMP nsNavHistoryQuery::GetTransitionCount(PRUint32 *aTransitionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean onlyBookmarked; */
NS_IMETHODIMP nsNavHistoryQuery::GetOnlyBookmarked(PRBool *aOnlyBookmarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetOnlyBookmarked(PRBool aOnlyBookmarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean domainIsHost; */
NS_IMETHODIMP nsNavHistoryQuery::GetDomainIsHost(PRBool *aDomainIsHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetDomainIsHost(PRBool aDomainIsHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String domain; */
NS_IMETHODIMP nsNavHistoryQuery::GetDomain(nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetDomain(const nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasDomain; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasDomain(PRBool *aHasDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean uriIsPrefix; */
NS_IMETHODIMP nsNavHistoryQuery::GetUriIsPrefix(PRBool *aUriIsPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetUriIsPrefix(PRBool aUriIsPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsNavHistoryQuery::GetUri(nsIURI **aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasUri; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasUri(PRBool *aHasUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean annotationIsNot; */
NS_IMETHODIMP nsNavHistoryQuery::GetAnnotationIsNot(PRBool *aAnnotationIsNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetAnnotationIsNot(PRBool aAnnotationIsNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String annotation; */
NS_IMETHODIMP nsNavHistoryQuery::GetAnnotation(nsACString & aAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetAnnotation(const nsACString & aAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasAnnotation; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasAnnotation(PRBool *aHasAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant tags; */
NS_IMETHODIMP nsNavHistoryQuery::GetTags(nsIVariant **aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetTags(nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean tagsAreNot; */
NS_IMETHODIMP nsNavHistoryQuery::GetTagsAreNot(PRBool *aTagsAreNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetTagsAreNot(PRBool aTagsAreNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFolders ([optional] out unsigned long count, [array, size_is (count), retval] out long long folders); */
NS_IMETHODIMP nsNavHistoryQuery::GetFolders(PRUint32 *count NS_OUTPARAM, PRInt64 **folders NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long folderCount; */
NS_IMETHODIMP nsNavHistoryQuery::GetFolderCount(PRUint32 *aFolderCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFolders ([array, size_is (folderCount), const] in long long folders, in unsigned long folderCount); */
NS_IMETHODIMP nsNavHistoryQuery::SetFolders(const PRInt64 *folders, PRUint32 folderCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQuery clone (); */
NS_IMETHODIMP nsNavHistoryQuery::Clone(nsINavHistoryQuery **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQueryOptions */
#define NS_INAVHISTORYQUERYOPTIONS_IID_STR "2d8ff86b-f8c2-451c-8a1a-1ff0749a074e"

#define NS_INAVHISTORYQUERYOPTIONS_IID \
  {0x2d8ff86b, 0xf8c2, 0x451c, \
    { 0x8a, 0x1a, 0x1f, 0xf0, 0x74, 0x9a, 0x07, 0x4e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryQueryOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERYOPTIONS_IID)

  /**
 * This object represents the global options for executing a query.
 */
/**
   * You can ask for the results to be pre-sorted. Since the DB has indices
   * of many items, it can produce sorted results almost for free. These should
   * be self-explanatory.
   *
   * Note: re-sorting is slower, as is sorting by title or when you have a
   * host name.
   *
   * For bookmark items, SORT_BY_NONE means sort by the natural bookmark order.
   */
  enum { SORT_BY_NONE = 0U };

  enum { SORT_BY_TITLE_ASCENDING = 1U };

  enum { SORT_BY_TITLE_DESCENDING = 2U };

  enum { SORT_BY_DATE_ASCENDING = 3U };

  enum { SORT_BY_DATE_DESCENDING = 4U };

  enum { SORT_BY_URI_ASCENDING = 5U };

  enum { SORT_BY_URI_DESCENDING = 6U };

  enum { SORT_BY_VISITCOUNT_ASCENDING = 7U };

  enum { SORT_BY_VISITCOUNT_DESCENDING = 8U };

  enum { SORT_BY_KEYWORD_ASCENDING = 9U };

  enum { SORT_BY_KEYWORD_DESCENDING = 10U };

  enum { SORT_BY_DATEADDED_ASCENDING = 11U };

  enum { SORT_BY_DATEADDED_DESCENDING = 12U };

  enum { SORT_BY_LASTMODIFIED_ASCENDING = 13U };

  enum { SORT_BY_LASTMODIFIED_DESCENDING = 14U };

  enum { SORT_BY_TAGS_ASCENDING = 17U };

  enum { SORT_BY_TAGS_DESCENDING = 18U };

  enum { SORT_BY_ANNOTATION_ASCENDING = 19U };

  enum { SORT_BY_ANNOTATION_DESCENDING = 20U };

  /**
   * "URI" results, one for each URI visited in the range. Individual result
   * nodes will be of type "URI".
   */
  enum { RESULTS_AS_URI = 0U };

  /**
   * "Visit" results, with one for each time a page was visited (this will
   * often give you multiple results for one URI). Individual result nodes will
   * have type "Visit"
   *
   * @note This result type is only supported by QUERY_TYPE_HISTORY.
   */
  enum { RESULTS_AS_VISIT = 1U };

  /**
   * This is identical to RESULT_TYPE_VISIT except that individual result nodes
   * will have type "FullVisit".  This is used for the attributes that are not
   * commonly accessed to save space in the common case (the lists can be very
   * long).
   *
   * @note Not yet implemented. See bug 409662.
   * @note This result type is only supported by QUERY_TYPE_HISTORY.
   */
  enum { RESULTS_AS_FULL_VISIT = 2U };

  /**
   * This returns query nodes for each predefined date range where we 
   * had visits. The node contains information how to load its content:
   * - visits for the given date range will be loaded.
   *
   * @note This result type is only supported by QUERY_TYPE_HISTORY.
   */
  enum { RESULTS_AS_DATE_QUERY = 3U };

  /**
   * This returns nsINavHistoryQueryResultNode nodes for each site where we 
   * have visits. The node contains information how to load its content:
   * - last visit for each url in the given host will be loaded.
   *
   * @note This result type is only supported by QUERY_TYPE_HISTORY.
   */
  enum { RESULTS_AS_SITE_QUERY = 4U };

  /**
   * This returns nsINavHistoryQueryResultNode nodes for each day where we 
   * have visits. The node contains information how to load its content:
   * - list of hosts visited in the given period will be loaded.
   *
   * @note This result type is only supported by QUERY_TYPE_HISTORY.
   */
  enum { RESULTS_AS_DATE_SITE_QUERY = 5U };

  /**
   * This returns nsINavHistoryQueryResultNode nodes for each tag.
   * The node contains information how to load its content:
   * - list of bookmarks with the given tag will be loaded.
   *
   * @note Setting this resultType will force queryType to QUERY_TYPE_BOOKMARKS.
   */
  enum { RESULTS_AS_TAG_QUERY = 6U };

  /**
   * This is a container with an URI result type that contains the last
   * modified bookmarks for the given tag.
   * Tag folder id must be defined in the query.
   *
   * @note Setting this resultType will force queryType to QUERY_TYPE_BOOKMARKS.
   */
  enum { RESULTS_AS_TAG_CONTENTS = 7U };

  /**
   * The sorting mode to be used for this query.
   * mode is one of SORT_BY_*
   */
  /* attribute unsigned short sortingMode; */
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode) = 0;

  /**
   * The annotation to use in SORT_BY_ANNOTATION_* sorting modes.
   */
  /* attribute AUTF8String sortingAnnotation; */
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) = 0;

  /**
   * Sets the result type. One of RESULT_TYPE_* which includes how URIs are
   * represented.
   */
  /* attribute unsigned short resultType; */
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetResultType(PRUint16 aResultType) = 0;

  /**
   * This option excludes all URIs and separators from a bookmarks query.
   * This would be used if you just wanted a list of bookmark folders and
   * queries (such as the left pane of the places page).
   * Defaults to false.
   */
  /* attribute boolean excludeItems; */
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItems(PRBool *aExcludeItems) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItems(PRBool aExcludeItems) = 0;

  /**
   * Set to true to exclude queries ("place:" URIs) from the query results.
   * Simple folder queries (bookmark folder symlinks) will still be included.
   * Defaults to false.
   */
  /* attribute boolean excludeQueries; */
  NS_SCRIPTABLE NS_IMETHOD GetExcludeQueries(PRBool *aExcludeQueries) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExcludeQueries(PRBool aExcludeQueries) = 0;

  /**
   * Set to true to exclude read-only folders from the query results. This is
   * designed for cases where you want to give the user the option of filing
   * something into a list of folders. It only affects cases where the actual
   * folder result node would appear in its parent folder and filters it out.
   * It doesn't affect the query at all, and doesn't affect more complex
   * queries (such as "folders with annotation X").
   */
  /* attribute boolean excludeReadOnlyFolders; */
  NS_SCRIPTABLE NS_IMETHOD GetExcludeReadOnlyFolders(PRBool *aExcludeReadOnlyFolders) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExcludeReadOnlyFolders(PRBool aExcludeReadOnlyFolders) = 0;

  /**
   * This option excludes items from a bookmarks query
   * if the parent of the item has this annotation.
   * An example is to exclude livemark items
   * (parent folders have the "livemark/feedURI" annotation)
   * Ignored for queries over history.
   */
  /* attribute AUTF8String excludeItemIfParentHasAnnotation; */
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItemIfParentHasAnnotation(nsACString & aExcludeItemIfParentHasAnnotation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItemIfParentHasAnnotation(const nsACString & aExcludeItemIfParentHasAnnotation) = 0;

  /**
   * When set, allows items with "place:" URIs to appear as containers,
   * with the container's contents filled in from the stored query.
   * If not set, these will appear as normal items. Doesn't do anything if
   * excludeQueries is set. Defaults to false.
   *
   * Note that this has no effect on folder links, which are place: URIs
   * returned by nsINavBookmarkService.GetFolderURI. These are always expanded
   * and will appear as bookmark folders.
   */
  /* attribute boolean expandQueries; */
  NS_SCRIPTABLE NS_IMETHOD GetExpandQueries(PRBool *aExpandQueries) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetExpandQueries(PRBool aExpandQueries) = 0;

  /**
   * Most items in history are marked "hidden." Only toplevel pages that the
   * user sees in the URL bar are not hidden. Hidden things include the content
   * of iframes and all images on web pages. Normally, you don't want these
   * things. If you do, set this flag and you'll get all items, even hidden
   * ones. Does nothing for bookmark queries. Defaults to false.
   */
  /* attribute boolean includeHidden; */
  NS_SCRIPTABLE NS_IMETHOD GetIncludeHidden(PRBool *aIncludeHidden) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIncludeHidden(PRBool aIncludeHidden) = 0;

  /**
   * Include both redirected-from and redirected-to pages into results.
   */
  enum { REDIRECTS_MODE_ALL = 0U };

  /**
   * Query results will not include redirected-to pages, but will include
   * redirected-from pages.
   */
  enum { REDIRECTS_MODE_SOURCE = 1U };

  /**
   * Query results will not include redirected-from pages but will include
   * redirected-to pages.
   */
  enum { REDIRECTS_MODE_TARGET = 2U };

  /**
   * Defines how redirects should be handled, see REDIRECTS_MODE_* constants
   * above.
   * Defaults to REDIRECTS_MODE_ALL.
   * Note: this option is effective only on QUERY_TYPE_HISTORY.
   */
  /* attribute unsigned short redirectsMode; */
  NS_SCRIPTABLE NS_IMETHOD GetRedirectsMode(PRUint16 *aRedirectsMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRedirectsMode(PRUint16 aRedirectsMode) = 0;

  /**
   * This is the maximum number of results that you want. The query is exeucted,
   * the results are sorted, and then the top 'maxResults' results are taken
   * and returned. Set to 0 (the default) to get all results.
   *
   * THIS DOES NOT WORK IN CONJUNCTION WITH SORTING BY TITLE. This is because
   * sorting by title requires us to sort after using locale-sensetive sorting
   * (as opposed to letting the database do it for us).
   *
   * Instead, we get the result ordered by date, pick the maxResult most recent
   * ones, and THEN sort by title.
   */
  /* attribute unsigned long maxResults; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxResults(PRUint32 *aMaxResults) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaxResults(PRUint32 aMaxResults) = 0;

  enum { QUERY_TYPE_HISTORY = 0U };

  enum { QUERY_TYPE_BOOKMARKS = 1U };

  enum { QUERY_TYPE_UNIFIED = 2U };

  /**
   * The type of search to use when querying the DB; This attribute is only
   * honored by query nodes. It is silently ignored for simple folder queries.
   */
  /* attribute unsigned short queryType; */
  NS_SCRIPTABLE NS_IMETHOD GetQueryType(PRUint16 *aQueryType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetQueryType(PRUint16 aQueryType) = 0;

  /**
   * When this is true, the root container node generated by these options and
   * its descendant containers will be opened asynchronously if they support it.
   * This is false by default.
   *
   * @note Currently only bookmark folder containers support being opened
   *       asynchronously.
   */
  /* attribute boolean asyncEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetAsyncEnabled(PRBool *aAsyncEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAsyncEnabled(PRBool aAsyncEnabled) = 0;

  /**
   * Creates a new options item with the same parameters of this one.
   */
  /* nsINavHistoryQueryOptions clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQueryOptions **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQueryOptions, NS_INAVHISTORYQUERYOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERYOPTIONS \
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode); \
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode); \
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType); \
  NS_SCRIPTABLE NS_IMETHOD SetResultType(PRUint16 aResultType); \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItems(PRBool *aExcludeItems); \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItems(PRBool aExcludeItems); \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeQueries(PRBool *aExcludeQueries); \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeQueries(PRBool aExcludeQueries); \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeReadOnlyFolders(PRBool *aExcludeReadOnlyFolders); \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeReadOnlyFolders(PRBool aExcludeReadOnlyFolders); \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItemIfParentHasAnnotation(nsACString & aExcludeItemIfParentHasAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItemIfParentHasAnnotation(const nsACString & aExcludeItemIfParentHasAnnotation); \
  NS_SCRIPTABLE NS_IMETHOD GetExpandQueries(PRBool *aExpandQueries); \
  NS_SCRIPTABLE NS_IMETHOD SetExpandQueries(PRBool aExpandQueries); \
  NS_SCRIPTABLE NS_IMETHOD GetIncludeHidden(PRBool *aIncludeHidden); \
  NS_SCRIPTABLE NS_IMETHOD SetIncludeHidden(PRBool aIncludeHidden); \
  NS_SCRIPTABLE NS_IMETHOD GetRedirectsMode(PRUint16 *aRedirectsMode); \
  NS_SCRIPTABLE NS_IMETHOD SetRedirectsMode(PRUint16 aRedirectsMode); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxResults(PRUint32 *aMaxResults); \
  NS_SCRIPTABLE NS_IMETHOD SetMaxResults(PRUint32 aMaxResults); \
  NS_SCRIPTABLE NS_IMETHOD GetQueryType(PRUint16 *aQueryType); \
  NS_SCRIPTABLE NS_IMETHOD SetQueryType(PRUint16 aQueryType); \
  NS_SCRIPTABLE NS_IMETHOD GetAsyncEnabled(PRBool *aAsyncEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetAsyncEnabled(PRBool aAsyncEnabled); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQueryOptions **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERYOPTIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode) { return _to GetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode) { return _to SetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return _to GetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return _to SetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType) { return _to GetResultType(aResultType); } \
  NS_SCRIPTABLE NS_IMETHOD SetResultType(PRUint16 aResultType) { return _to SetResultType(aResultType); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItems(PRBool *aExcludeItems) { return _to GetExcludeItems(aExcludeItems); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItems(PRBool aExcludeItems) { return _to SetExcludeItems(aExcludeItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeQueries(PRBool *aExcludeQueries) { return _to GetExcludeQueries(aExcludeQueries); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeQueries(PRBool aExcludeQueries) { return _to SetExcludeQueries(aExcludeQueries); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeReadOnlyFolders(PRBool *aExcludeReadOnlyFolders) { return _to GetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeReadOnlyFolders(PRBool aExcludeReadOnlyFolders) { return _to SetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItemIfParentHasAnnotation(nsACString & aExcludeItemIfParentHasAnnotation) { return _to GetExcludeItemIfParentHasAnnotation(aExcludeItemIfParentHasAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItemIfParentHasAnnotation(const nsACString & aExcludeItemIfParentHasAnnotation) { return _to SetExcludeItemIfParentHasAnnotation(aExcludeItemIfParentHasAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpandQueries(PRBool *aExpandQueries) { return _to GetExpandQueries(aExpandQueries); } \
  NS_SCRIPTABLE NS_IMETHOD SetExpandQueries(PRBool aExpandQueries) { return _to SetExpandQueries(aExpandQueries); } \
  NS_SCRIPTABLE NS_IMETHOD GetIncludeHidden(PRBool *aIncludeHidden) { return _to GetIncludeHidden(aIncludeHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetIncludeHidden(PRBool aIncludeHidden) { return _to SetIncludeHidden(aIncludeHidden); } \
  NS_SCRIPTABLE NS_IMETHOD GetRedirectsMode(PRUint16 *aRedirectsMode) { return _to GetRedirectsMode(aRedirectsMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetRedirectsMode(PRUint16 aRedirectsMode) { return _to SetRedirectsMode(aRedirectsMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxResults(PRUint32 *aMaxResults) { return _to GetMaxResults(aMaxResults); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxResults(PRUint32 aMaxResults) { return _to SetMaxResults(aMaxResults); } \
  NS_SCRIPTABLE NS_IMETHOD GetQueryType(PRUint16 *aQueryType) { return _to GetQueryType(aQueryType); } \
  NS_SCRIPTABLE NS_IMETHOD SetQueryType(PRUint16 aQueryType) { return _to SetQueryType(aQueryType); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsyncEnabled(PRBool *aAsyncEnabled) { return _to GetAsyncEnabled(aAsyncEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsyncEnabled(PRBool aAsyncEnabled) { return _to SetAsyncEnabled(aAsyncEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQueryOptions **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERYOPTIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSortingMode(PRUint16 *aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingMode(PRUint16 aSortingMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingMode(aSortingMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingAnnotation(aSortingAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultType(aResultType); } \
  NS_SCRIPTABLE NS_IMETHOD SetResultType(PRUint16 aResultType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResultType(aResultType); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItems(PRBool *aExcludeItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeItems(aExcludeItems); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItems(PRBool aExcludeItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeItems(aExcludeItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeQueries(PRBool *aExcludeQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeQueries(aExcludeQueries); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeQueries(PRBool aExcludeQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeQueries(aExcludeQueries); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeReadOnlyFolders(PRBool *aExcludeReadOnlyFolders) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeReadOnlyFolders(PRBool aExcludeReadOnlyFolders) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_SCRIPTABLE NS_IMETHOD GetExcludeItemIfParentHasAnnotation(nsACString & aExcludeItemIfParentHasAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeItemIfParentHasAnnotation(aExcludeItemIfParentHasAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD SetExcludeItemIfParentHasAnnotation(const nsACString & aExcludeItemIfParentHasAnnotation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeItemIfParentHasAnnotation(aExcludeItemIfParentHasAnnotation); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpandQueries(PRBool *aExpandQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpandQueries(aExpandQueries); } \
  NS_SCRIPTABLE NS_IMETHOD SetExpandQueries(PRBool aExpandQueries) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpandQueries(aExpandQueries); } \
  NS_SCRIPTABLE NS_IMETHOD GetIncludeHidden(PRBool *aIncludeHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIncludeHidden(aIncludeHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetIncludeHidden(PRBool aIncludeHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIncludeHidden(aIncludeHidden); } \
  NS_SCRIPTABLE NS_IMETHOD GetRedirectsMode(PRUint16 *aRedirectsMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectsMode(aRedirectsMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetRedirectsMode(PRUint16 aRedirectsMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRedirectsMode(aRedirectsMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxResults(PRUint32 *aMaxResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxResults(aMaxResults); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxResults(PRUint32 aMaxResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxResults(aMaxResults); } \
  NS_SCRIPTABLE NS_IMETHOD GetQueryType(PRUint16 *aQueryType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryType(aQueryType); } \
  NS_SCRIPTABLE NS_IMETHOD SetQueryType(PRUint16 aQueryType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetQueryType(aQueryType); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsyncEnabled(PRBool *aAsyncEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncEnabled(aAsyncEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsyncEnabled(PRBool aAsyncEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsyncEnabled(aAsyncEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsINavHistoryQueryOptions **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQueryOptions : public nsINavHistoryQueryOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERYOPTIONS

  nsNavHistoryQueryOptions();

private:
  ~nsNavHistoryQueryOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryQueryOptions, nsINavHistoryQueryOptions)

nsNavHistoryQueryOptions::nsNavHistoryQueryOptions()
{
  /* member initializers and constructor code */
}

nsNavHistoryQueryOptions::~nsNavHistoryQueryOptions()
{
  /* destructor code */
}

/* attribute unsigned short sortingMode; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetSortingMode(PRUint16 *aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetSortingMode(PRUint16 aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String sortingAnnotation; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetSortingAnnotation(nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetSortingAnnotation(const nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short resultType; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetResultType(PRUint16 *aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetResultType(PRUint16 aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeItems; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeItems(PRBool *aExcludeItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeItems(PRBool aExcludeItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeQueries; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeQueries(PRBool *aExcludeQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeQueries(PRBool aExcludeQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeReadOnlyFolders; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeReadOnlyFolders(PRBool *aExcludeReadOnlyFolders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeReadOnlyFolders(PRBool aExcludeReadOnlyFolders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String excludeItemIfParentHasAnnotation; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeItemIfParentHasAnnotation(nsACString & aExcludeItemIfParentHasAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeItemIfParentHasAnnotation(const nsACString & aExcludeItemIfParentHasAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean expandQueries; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExpandQueries(PRBool *aExpandQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExpandQueries(PRBool aExpandQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean includeHidden; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetIncludeHidden(PRBool *aIncludeHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetIncludeHidden(PRBool aIncludeHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short redirectsMode; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetRedirectsMode(PRUint16 *aRedirectsMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetRedirectsMode(PRUint16 aRedirectsMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long maxResults; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetMaxResults(PRUint32 *aMaxResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetMaxResults(PRUint32 aMaxResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short queryType; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetQueryType(PRUint16 *aQueryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetQueryType(PRUint16 aQueryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean asyncEnabled; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetAsyncEnabled(PRBool *aAsyncEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetAsyncEnabled(PRBool aAsyncEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQueryOptions clone (); */
NS_IMETHODIMP nsNavHistoryQueryOptions::Clone(nsINavHistoryQueryOptions **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryService */
#define NS_INAVHISTORYSERVICE_IID_STR "437f539b-d541-4a0f-a200-6f9a6d45cce2"

#define NS_INAVHISTORYSERVICE_IID \
  {0x437f539b, 0xd541, 0x4a0f, \
    { 0xa2, 0x00, 0x6f, 0x9a, 0x6d, 0x45, 0xcc, 0xe2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYSERVICE_IID)

  /**
   * System Notifications:
   *
   * places-init-complete - Sent once the History service is completely
   *                        initialized successfully.
   * places-database-locked - Sent if initialization of the History service
   *                          failed due to the inability to open the places.sqlite
   *                          for access reasons.
   */
/**
   * This transition type means the user followed a link and got a new toplevel
   * window.
   */
  enum { TRANSITION_LINK = 1U };

  /**
   * This transition type means that the user typed the page's URL in the
   * URL bar or selected it from URL bar autocomplete results, clicked on
   * it from a history query (from the History sidebar, History menu, 
   * or history query in the personal toolbar or Places organizer.
   */
  enum { TRANSITION_TYPED = 2U };

  /**
   * This transition is set when the user followed a bookmark to get to the
   * page.
   */
  enum { TRANSITION_BOOKMARK = 3U };

  /**
   * This transition type is set when some inner content is loaded. This is
   * true of all images on a page, and the contents of the iframe. It is also
   * true of any content in a frame if the user did not explicitly follow
   * a link to get there.
   */
  enum { TRANSITION_EMBED = 4U };

  /**
   * Set when the transition was a permanent redirect.
   */
  enum { TRANSITION_REDIRECT_PERMANENT = 5U };

  /**
   * Set when the transition was a temporary redirect.
   */
  enum { TRANSITION_REDIRECT_TEMPORARY = 6U };

  /**
   * Set when the transition is a download.
   */
  enum { TRANSITION_DOWNLOAD = 7U };

  /**
   * This transition type means the user followed a link and got a visit in
   * a frame.
   */
  enum { TRANSITION_FRAMED_LINK = 8U };

  /**
   * Set when database is coherent
   */
  enum { DATABASE_STATUS_OK = 0U };

  /**
   * Set when database did not exist and we created a new one
   */
  enum { DATABASE_STATUS_CREATE = 1U };

  /**
   * Set when database was corrupt and we replaced it
   */
  enum { DATABASE_STATUS_CORRUPT = 2U };

  /**
   * Set when database schema has been upgraded
   */
  enum { DATABASE_STATUS_UPGRADED = 3U };

  /**
   * Returns the current database status
   */
  /* readonly attribute unsigned short databaseStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseStatus(PRUint16 *aDatabaseStatus) = 0;

  /**
   * True if there is any history. This can be used in UI to determine whether
   * the "clear history" button should be enabled or not. This is much better
   * than using BrowserHistory.count since that can be very slow if there is
   * a lot of history (it must enumerate each item). This is pretty fast.
   */
  /* readonly attribute boolean hasHistoryEntries; */
  NS_SCRIPTABLE NS_IMETHOD GetHasHistoryEntries(PRBool *aHasHistoryEntries) = 0;

  /**
   * Gets the original title of the page.
   */
  /* AString getPageTitle (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * This is just like markPageAsTyped (in nsIBrowserHistory, also implemented
   * by the history service), but for bookmarks. It declares that the given URI
   * is being opened as a result of following a bookmark. If this URI is loaded
   * soon after this message has been received, that transition will be marked
   * as following a bookmark.
   */
  /* void markPageAsFollowedBookmark (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) = 0;

  /**
   * Gets the stored character-set for an URI.
   *
   * @param aURI
   *        URI to retrieve character-set for
   * @return character-set, empty string if not found
   */
  /* AString getCharsetForURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Sets the character-set for an URI.
   *
   * @param aURI
   *        URI to set the character-set for
   * @param aCharset
   *        character-set to be set
   */
  /* void setCharsetForURI (in nsIURI aURI, in AString aCharset); */
  NS_SCRIPTABLE NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset) = 0;

  /**
   * Returns true if this URI would be added to the history. You don't have to
   * worry about calling this, addPageToSession/addURI will always check before
   * actually adding the page. This function is public because some components
   * may want to check if this page would go in the history (i.e. for
   * annotations).
   */
  /* boolean canAddURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD CanAddURI(nsIURI *aURI, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Call to manually add a visit for a specific page. This will probably not
   * be commonly used other than for backup/restore type operations. If the URI
   * does not have an entry in the history database already, one will be created
   * with no visits, no title, hidden, not typed.  Adding a visit will
   * automatically increment the visit count for the visited page and will unhide
   * it and/or mark it typed according to the transition type.
   *
   * @param aURI             Visited page
   * @param aTime            Time page was visited (microseconds)
   * @param aReferringURI    The URI of the visit that generated this one. Use
   *                         null for no referrer.
   * @param aTranstitionType Type of transition: one of TRANSITION_* above
   * @param aIsRedirect      True if the given visit redirects to somewhere else.
   *                         (ie you will create an visit out of here that is a
   *                         redirect transition). This causes this page to be
   *                         hidden in normal history views (unless it has been
   *                         unhidden by visiting it with a non-redirect).
   * @param aSessionID       The session ID that this page belongs to. Use 0 for
   *                         no session.
   * @return The ID of the created visit. This will be 0 if the URI cannot
   *         be added to history (canAddURI = false) or the visit is session
   *         persistent (TRANSITION_EMBED).
   */
  /* long long addVisit (in nsIURI aURI, in PRTime aTime, in nsIURI aReferringURI, in long aTransitionType, in boolean aIsRedirect, in long long aSessionID); */
  NS_SCRIPTABLE NS_IMETHOD AddVisit(nsIURI *aURI, PRTime aTime, nsIURI *aReferringURI, PRInt32 aTransitionType, PRBool aIsRedirect, PRInt64 aSessionID, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * This returns a new query object that you can pass to executeQuer[y/ies].
   * It will be initialized to all empty (so using it will give you all history).
   */
  /* nsINavHistoryQuery getNewQuery (); */
  NS_SCRIPTABLE NS_IMETHOD GetNewQuery(nsINavHistoryQuery **_retval NS_OUTPARAM) = 0;

  /**
   * This returns a new options object that you can pass to executeQuer[y/ies]
   * after setting the desired options.
   */
  /* nsINavHistoryQueryOptions getNewQueryOptions (); */
  NS_SCRIPTABLE NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions **_retval NS_OUTPARAM) = 0;

  /**
   * Executes a single query.
   */
  /* nsINavHistoryResult executeQuery (in nsINavHistoryQuery aQuery, in nsINavHistoryQueryOptions options); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM) = 0;

  /**
   * Executes an array of queries. All of the query objects are ORed
   * together. Within a query, all the terms are ANDed together as in
   * executeQuery. See executeQuery()
   */
  /* nsINavHistoryResult executeQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM) = 0;

  /**
   * Converts a query URI-like string to an array of actual query objects for
   * use to executeQueries(). The output query array may be empty if there is
   * no information. However, there will always be an options structure returned
   * (if nothing is defined, it will just have the default values).
   */
  /* void queryStringToQueries (in AUTF8String aQueryString, [array, size_is (aResultCount)] out nsINavHistoryQuery aQueries, out unsigned long aResultCount, out nsINavHistoryQueryOptions options); */
  NS_SCRIPTABLE NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery ***aQueries NS_OUTPARAM, PRUint32 *aResultCount NS_OUTPARAM, nsINavHistoryQueryOptions **options NS_OUTPARAM) = 0;

  /**
   * Converts a query into an equivalent string that can be persisted. Inverse
   * of queryStringToQueries()
   */
  /* AUTF8String queriesToQueryString ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
  NS_SCRIPTABLE NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Adds a history observer. If ownsWeak is false, the history service will
   * keep an owning reference to the observer.  If ownsWeak is true, then
   * aObserver must implement nsISupportsWeakReference, and the history service
   * will keep a weak reference to the observer.
   */
  /* void addObserver (in nsINavHistoryObserver observer, in boolean ownsWeak); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, PRBool ownsWeak) = 0;

  /**
   * Removes a history observer.
   */
  /* void removeObserver (in nsINavHistoryObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) = 0;

  /**
   * Runs the passed callback in batch mode. Use this when a lot of things
   * are about to change. Calls can be nested, observers will only be
   * notified when all batches begin/end.
   *
   * @param aCallback
   *        nsINavHistoryBatchCallback interface to call.
   * @param aUserData
   *        Opaque parameter passed to nsINavBookmarksBatchCallback
   */
  /* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aClosure); */
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) = 0;

  /** 
   * True if history is disabled. currently, 
   * history is disabled if the places.history.enabled pref is false.
   */
  /* readonly attribute boolean historyDisabled; */
  NS_SCRIPTABLE NS_IMETHOD GetHistoryDisabled(PRBool *aHistoryDisabled) = 0;

  /**
   * Import the given Mork history file.
   *  @param file     The Mork history file to import
   */
  /* void importHistory (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD ImportHistory(nsIFile *file) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryService, NS_INAVHISTORYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseStatus(PRUint16 *aDatabaseStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetHasHistoryEntries(PRBool *aHasHistoryEntries); \
  NS_SCRIPTABLE NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset); \
  NS_SCRIPTABLE NS_IMETHOD CanAddURI(nsIURI *aURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddVisit(nsIURI *aURI, PRTime aTime, nsIURI *aReferringURI, PRInt32 aTransitionType, PRBool aIsRedirect, PRInt64 aSessionID, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNewQuery(nsINavHistoryQuery **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery ***aQueries NS_OUTPARAM, PRUint32 *aResultCount NS_OUTPARAM, nsINavHistoryQueryOptions **options NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, PRBool ownsWeak); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure); \
  NS_SCRIPTABLE NS_IMETHOD GetHistoryDisabled(PRBool *aHistoryDisabled); \
  NS_SCRIPTABLE NS_IMETHOD ImportHistory(nsIFile *file); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseStatus(PRUint16 *aDatabaseStatus) { return _to GetDatabaseStatus(aDatabaseStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasHistoryEntries(PRBool *aHasHistoryEntries) { return _to GetHasHistoryEntries(aHasHistoryEntries); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return _to GetPageTitle(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) { return _to MarkPageAsFollowedBookmark(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return _to GetCharsetForURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset) { return _to SetCharsetForURI(aURI, aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD CanAddURI(nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return _to CanAddURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddVisit(nsIURI *aURI, PRTime aTime, nsIURI *aReferringURI, PRInt32 aTransitionType, PRBool aIsRedirect, PRInt64 aSessionID, PRInt64 *_retval NS_OUTPARAM) { return _to AddVisit(aURI, aTime, aReferringURI, aTransitionType, aIsRedirect, aSessionID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewQuery(nsINavHistoryQuery **_retval NS_OUTPARAM) { return _to GetNewQuery(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions **_retval NS_OUTPARAM) { return _to GetNewQueryOptions(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM) { return _to ExecuteQuery(aQuery, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM) { return _to ExecuteQueries(aQueries, aQueryCount, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery ***aQueries NS_OUTPARAM, PRUint32 *aResultCount NS_OUTPARAM, nsINavHistoryQueryOptions **options NS_OUTPARAM) { return _to QueryStringToQueries(aQueryString, aQueries, aResultCount, options); } \
  NS_SCRIPTABLE NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval NS_OUTPARAM) { return _to QueriesToQueryString(aQueries, aQueryCount, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, PRBool ownsWeak) { return _to AddObserver(observer, ownsWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) { return _to RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) { return _to RunInBatchMode(aCallback, aClosure); } \
  NS_SCRIPTABLE NS_IMETHOD GetHistoryDisabled(PRBool *aHistoryDisabled) { return _to GetHistoryDisabled(aHistoryDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD ImportHistory(nsIFile *file) { return _to ImportHistory(file); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDatabaseStatus(PRUint16 *aDatabaseStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabaseStatus(aDatabaseStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasHistoryEntries(PRBool *aHasHistoryEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasHistoryEntries(aHasHistoryEntries); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageTitle(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsFollowedBookmark(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharsetForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsetForURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharsetForURI(aURI, aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD CanAddURI(nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAddURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddVisit(nsIURI *aURI, PRTime aTime, nsIURI *aReferringURI, PRInt32 aTransitionType, PRBool aIsRedirect, PRInt64 aSessionID, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddVisit(aURI, aTime, aReferringURI, aTransitionType, aIsRedirect, aSessionID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewQuery(nsINavHistoryQuery **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewQuery(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewQueryOptions(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteQuery(aQuery, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteQueries(aQueries, aQueryCount, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery ***aQueries NS_OUTPARAM, PRUint32 *aResultCount NS_OUTPARAM, nsINavHistoryQueryOptions **options NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryStringToQueries(aQueryString, aQueries, aResultCount, options); } \
  NS_SCRIPTABLE NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueriesToQueryString(aQueries, aQueryCount, options, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, PRBool ownsWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer, ownsWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInBatchMode(aCallback, aClosure); } \
  NS_SCRIPTABLE NS_IMETHOD GetHistoryDisabled(PRBool *aHistoryDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryDisabled(aHistoryDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD ImportHistory(nsIFile *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportHistory(file); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryService : public nsINavHistoryService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYSERVICE

  nsNavHistoryService();

private:
  ~nsNavHistoryService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryService, nsINavHistoryService)

nsNavHistoryService::nsNavHistoryService()
{
  /* member initializers and constructor code */
}

nsNavHistoryService::~nsNavHistoryService()
{
  /* destructor code */
}

/* readonly attribute unsigned short databaseStatus; */
NS_IMETHODIMP nsNavHistoryService::GetDatabaseStatus(PRUint16 *aDatabaseStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasHistoryEntries; */
NS_IMETHODIMP nsNavHistoryService::GetHasHistoryEntries(PRBool *aHasHistoryEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getPageTitle (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::GetPageTitle(nsIURI *aURI, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsFollowedBookmark (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsFollowedBookmark(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCharsetForURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::GetCharsetForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCharsetForURI (in nsIURI aURI, in AString aCharset); */
NS_IMETHODIMP nsNavHistoryService::SetCharsetForURI(nsIURI *aURI, const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canAddURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::CanAddURI(nsIURI *aURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long addVisit (in nsIURI aURI, in PRTime aTime, in nsIURI aReferringURI, in long aTransitionType, in boolean aIsRedirect, in long long aSessionID); */
NS_IMETHODIMP nsNavHistoryService::AddVisit(nsIURI *aURI, PRTime aTime, nsIURI *aReferringURI, PRInt32 aTransitionType, PRBool aIsRedirect, PRInt64 aSessionID, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQuery getNewQuery (); */
NS_IMETHODIMP nsNavHistoryService::GetNewQuery(nsINavHistoryQuery **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQueryOptions getNewQueryOptions (); */
NS_IMETHODIMP nsNavHistoryService::GetNewQueryOptions(nsINavHistoryQueryOptions **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResult executeQuery (in nsINavHistoryQuery aQuery, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResult executeQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::ExecuteQueries(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void queryStringToQueries (in AUTF8String aQueryString, [array, size_is (aResultCount)] out nsINavHistoryQuery aQueries, out unsigned long aResultCount, out nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery ***aQueries NS_OUTPARAM, PRUint32 *aResultCount NS_OUTPARAM, nsINavHistoryQueryOptions **options NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String queriesToQueryString ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::QueriesToQueryString(nsINavHistoryQuery **aQueries, PRUint32 aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavHistoryObserver observer, in boolean ownsWeak); */
NS_IMETHODIMP nsNavHistoryService::AddObserver(nsINavHistoryObserver *observer, PRBool ownsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavHistoryObserver observer); */
NS_IMETHODIMP nsNavHistoryService::RemoveObserver(nsINavHistoryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aClosure); */
NS_IMETHODIMP nsNavHistoryService::RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean historyDisabled; */
NS_IMETHODIMP nsNavHistoryService::GetHistoryDisabled(PRBool *aHistoryDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importHistory (in nsIFile file); */
NS_IMETHODIMP nsNavHistoryService::ImportHistory(nsIFile *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryBatchCallback */
#define NS_INAVHISTORYBATCHCALLBACK_IID_STR "5143f2bb-be0a-4faf-9acb-b0ed3f82952c"

#define NS_INAVHISTORYBATCHCALLBACK_IID \
  {0x5143f2bb, 0xbe0a, 0x4faf, \
    { 0x9a, 0xcb, 0xb0, 0xed, 0x3f, 0x82, 0x95, 0x2c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsINavHistoryBatchCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYBATCHCALLBACK_IID)

  /**
 * @see runInBatchMode of nsINavHistoryService/nsINavBookmarksService
 */
  /* void runBatched (in nsISupports aUserData); */
  NS_SCRIPTABLE NS_IMETHOD RunBatched(nsISupports *aUserData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryBatchCallback, NS_INAVHISTORYBATCHCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYBATCHCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD RunBatched(nsISupports *aUserData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYBATCHCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD RunBatched(nsISupports *aUserData) { return _to RunBatched(aUserData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYBATCHCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD RunBatched(nsISupports *aUserData) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBatched(aUserData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryBatchCallback : public nsINavHistoryBatchCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYBATCHCALLBACK

  nsNavHistoryBatchCallback();

private:
  ~nsNavHistoryBatchCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavHistoryBatchCallback, nsINavHistoryBatchCallback)

nsNavHistoryBatchCallback::nsNavHistoryBatchCallback()
{
  /* member initializers and constructor code */
}

nsNavHistoryBatchCallback::~nsNavHistoryBatchCallback()
{
  /* destructor code */
}

/* void runBatched (in nsISupports aUserData); */
NS_IMETHODIMP nsNavHistoryBatchCallback::RunBatched(nsISupports *aUserData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavHistoryService_h__ */
