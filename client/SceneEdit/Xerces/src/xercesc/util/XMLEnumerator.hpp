/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: XMLEnumerator.hpp 191054 2005-06-17 02:56:35Z jberry $
 */


#if !defined(XMLENUMERATOR_HPP)
#define XMLENUMERATOR_HPP

#include <../../../SceneEdit/Xerces/src/xercesc/util/XercesDefs.hpp>

XERCES_CPP_NAMESPACE_BEGIN

template <class TElem> class XMLEnumerator
{
public :
    // -----------------------------------------------------------------------
    //  Destructor
    // -----------------------------------------------------------------------
    virtual ~XMLEnumerator() {};

    // -----------------------------------------------------------------------
    //  XMLEnumerator interface
    // -----------------------------------------------------------------------
    virtual bool hasMoreElements() const = 0;
    virtual TElem& nextElement() = 0;
    virtual void Reset() = 0;

    XMLEnumerator() {}
    XMLEnumerator(const XMLEnumerator<TElem>&) {}

private:
	// -----------------------------------------------------------------------
    //  Unimplemented operators
    // -----------------------------------------------------------------------
    XMLEnumerator<TElem>& operator=(const XMLEnumerator<TElem>&);    
};

XERCES_CPP_NAMESPACE_END

#endif
