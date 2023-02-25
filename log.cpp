/* SLiM - Simple Login Manager
 *  Copyright (C) 1997, 1998 Per Liden
 *  Copyright (C) 2004-06 Simone Rota <sip@varlock.com>
 *  Copyright (C) 2004-06 Johannes Winkelmann <jw@tks6.net>
 *  Copyright (C) 2022 Rob Pearce <slim@flitspace.org.uk>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 */

#include "const.h"
#include "log.h"
#include <iostream>

bool LogUnit::openLog(const char * filename)
{
	if (logFile.is_open()) {
		cerr << APPNAME
			<< ": opening a new Log file, while another is already open"
			<< endl;
		logFile.close();
	}
	logFile.open(filename, ios_base::app);

	return !(logFile.fail());
}

void LogUnit::closeLog()
{
	if (logFile.is_open())
		logFile.close();
}


/* Now instantiate a singleton for all the rest of the code to use */
LogUnit logStream;
