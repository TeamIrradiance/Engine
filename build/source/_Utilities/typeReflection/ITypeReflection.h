#include "TypeReflectionmacros.h"
#include "Variant.h"

// Add a type to the type infos array. For now this just stores
// name and size of a type.

/******************************************************************************/
/*!
\macros  meta_begin : begin defining a metatype   
\param   T
         - a default type or a struct/class object
*/
/******************************************************************************/
#define meta_begin( T ) _meta_begin(T)

/******************************************************************************/
/*!
\macros  meta_child : adding a child type to begined type
\param   addTo      : begined meta type
\param   varName    : define a member Variant inside begined type as a child
*/
/******************************************************************************/
#define meta_child(addTo,varName) _meta_child(addTo,varName)

/******************************************************************************/
/*!
\macros  meta_end : end of metatype defining
*/
/******************************************************************************/
#define meta_end() _meta_end()

/******************************************************************************/
/*!
\macros  meta_end : Allows code to get a pointer to a TypeInfo through a 
                    template type lookup ID.
*/
/******************************************************************************/
#define GET_TYPE_BY_TEMPLATE( T ) _GET_TYPE_BY_TEMPLATE(T)

/******************************************************************************/
/*!
\macros  GET_TYPE_BY_STRING : Allows code to get a pointer to a TypeInfo through a 
                              string
*/
/******************************************************************************/
#define GET_TYPE_BY_STRING( typeNameCharPointer ) _GET_TYPE_BY_STRING( typeNameCharPointer )
