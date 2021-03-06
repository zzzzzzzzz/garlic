/**
 * This Source Code Form is subject to the terms 
 * of the Mozilla Public License, v. 2.0. If a 
 * copy of the MPL was not distributed with this 
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <fstream>

#include <onion/log.h>
#include <string.h>

#include "utils.h"

std::string Garlic::realpath(const std::string& path)
{
	char *basefilename_c;
	basefilename_c=::realpath(path.c_str(),NULL);
	if (basefilename_c==NULL){
		ONION_ERROR("Error getting realpath %s: %s",path.c_str(), strerror(errno));
		throw(std::exception());
	}
	std::string ret=basefilename_c;
	free(basefilename_c);

	return ret;
}

std::string Garlic::file2string(const std::string &filename){
	std::ifstream ifs(filename);
	if (!ifs.is_open()){
// 		ONION_ERROR("Cant open file %s", filename.c_str());
		throw(std::exception());
	}
	return std::string ( (std::istreambuf_iterator<char>(ifs) ),
											(std::istreambuf_iterator<char>()    ) );
}

