/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-

   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2002,2003 Koblenz University
   Copyright (C) 2003 RoboCup Soccer Server 3D Maintenance Group
   $Id: sexpparser.h,v 1.1.2.2 2003/12/05 10:12:28 fruit Exp $

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifndef OXYGEN_SEXPPARSER_H
#define OXYGEN_SEXPPARSER_H

#include <sfsexp/sexp.h>
#include <oxygen/gamecontrolserver/baseparser.h>
#include <zeitgeist/class.h>

class SexpParser : public oxygen::BaseParser
{
public:
    SexpParser()
    {
    }

    ~SexpParser()
    {
    }

    TPredicateList Parse(const std::string& input);
    std::string Generate(const TPredicateList& input);

    static bool IsString(const boost::any& operand);

private:
    TParameterList SexpToList(const sexp_t* const sexp);
    TPredicate SexpToPlist(const sexp_t* const sexp);
    std::string ListToString(const TParameterList& lst);
    std::string PlistToString(const TPredicate& plist);

};

DECLARE_CLASS(SexpParser);


#endif // OXYGEN_SEXPPARSER_H
