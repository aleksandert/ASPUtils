#include "ASPUtils_i.h"

/// <summary>
/// De-references the VARIANT argument.  We receive variants by reference
/// when inside a VB 'for each|loop'.  We must de-reference VARIANTs because
/// Cache does not know how to compare (operator==) VARIANTs BYREF.
/// </summary>
/// <param name="pvar">The pvar.</param>
/// <returns></returns>
inline VARIANT VARIANTDREF(const VARIANT* pvar)
{
	return (V_VT(pvar) == (VT_VARIANT | VT_BYREF)) ? *(V_VARIANTREF(pvar)) : *pvar;
}