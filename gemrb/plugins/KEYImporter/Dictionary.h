/***************************************************************************
                         |Dictionary.h|  -  stolen Map class from MFC
                          -------------------
    begin                : |oct. 23. 2003|
    copyright            : (C) |2003| by |Avenger|
    email                : |@|
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#if !defined(AFX_DICTIONARY_H__4EAE07B5_C375_4191_85AC_E5E15DBCD07B__INCLUDED_)
#define AFX_DICTIONARY_H__4EAE07B5_C375_4191_85AC_E5E15DBCD07B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ctype.h>
#include "../../includes/win32def.h"
#include "../../includes/SClassID.h"

#define THIS_FILE "dictionary.h"

/////////////////////////////////////////////////////////////////////////////
// Dictionary<unsigned long, VALUE>

class Dictionary //: public CObject
{
protected:
	// Association
	struct MyAssoc
	{
		MyAssoc* pNext;
		const char *key;
		SClass_ID type;
		unsigned long value;
	};
public:
// Construction
	Dictionary(int nBlockSize = 10, int nHashTableSize=32769);

// Attributes
	// number of elements
	int GetCount() const;
	bool IsEmpty() const;

	// Lookup
	bool Lookup(const char *key, unsigned int type, unsigned long& rValue) const;

// Operations
	void SetAt(const char *key, unsigned int type, unsigned long newValue);
	void RemoveAll();
	void InitHashTable(unsigned int hashSize, bool bAllocNow = true);

// Implementation
protected:
	MyAssoc** m_pHashTable;
	unsigned int m_nHashTableSize;
	int m_nCount;
	MyAssoc* m_pFreeList;
	struct Plex* m_pBlocks;
	int m_nBlockSize;

	MyAssoc* NewAssoc();
	void FreeAssoc(MyAssoc*);
	MyAssoc* GetAssocAt(const char *, unsigned int, unsigned int&) const;
        unsigned int MyHashKey(const char *, unsigned int) const;

public:
	~Dictionary();
};

#endif // !defined(AFX_DICTIONARY_H__4EAE07B5_C375_4191_85AC_E5E15DBCD07B__INCLUDED_)
