/*
	@title C-SMF v1.1
	@description Connect from SMF to SA-MP
	@author Carlton (%94) - Functions and everything | Seif: (%6) - strins, strmid, string loading edits.
	@functions
	    native OnCSMFInit();
	    native FormatRealName(bool:_RealName, _field[], _name[], _id);

		native GetMemberNameByID(_id[], bool:_RealName);
		native GetMemberIDByName(_name[], bool:_RealName);
		native GetMemberUMessagesByID(_id, bool:_RealName);
		native GetMemberUMessagesByName(_name[], bool:_RealName);
		native GetMemberGroupByID(_id, bool:_RealName);
		native GetMemberGroupByName(_name[], bool:_RealName);
		native GetMemberPostsByID(_id, bool:_RealName);
		native GetMemberPostsByName(_name[], bool:_RealName);
		native GetMemberIPByName(_name[], bool:_RealName);
		native GetMemberIPByID(_id, bool:_RealName);
		native GetMemberIP2ByName(_name[], bool:_RealName);
		native GetMemberIP2ByID(_id, bool:_RealName);
		native CheckUserNameAndPassword(_name[], Password__[], bool:_RealName);
		
		native GetForumNews();
		native GetForumSMTP_Username();
		native GetForumSMTP_Port();
		native GetCategoryNameByID(_id);
		native GetBoardNameByID(_id);
		native GetBoardIDByName(_name[]);
		native GetBoardCategoryByID(_id);
		native GetBoardCategoryByName(_name[]);
	@authornotes
	    Well, decided to do something different from other releases. C-SMF
	    connects straight from the SMF members to the players, accounts can be
	    linked through login. View example.pwn for an example script.
	@uses
	    To retreive a player's posts, IP, group, and unread messages!
*/

#include <a_mysql>

#define SMF_HOST "localhost"
#define SMF_DB "smf"
#define SMF_USER "root"
#define SMF_PASSWORD ""

#define MEMBERTABLE "smf_members"
#define SETTINGSTABLE "smf_settings"
#define CATEGORYTABLE "smf_categories"
#define BOARDTABLE "smf_boards"

#if !defined function
#define function%0(%1) stock%0(%1)
#endif

enum SMF {
    ID_MEMBER,
    memberName[50],
    posts,
    ID_GROUP,
    realName[50],
    unreadMessages,
    emailAddres,
    memberIP[16],
    memberIP2[16]
}

new
	SMFConnection,
	SMFMemberData[SMF],
	__string[128],
	__blank[128],
	__Escape[2][90];
	
//===============================[SMF2 data]=================================
function GetBoardCategoryByID(_id) {
	format(__string, 128, "SELECT ID_CAT FROM %s WHERE ID_BOARD = %i", BOARDTABLE, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	__id = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return __id;
}
function GetBoardCategoryByName(_name[]) {
	format(__string, 128, "SELECT ID_CAT FROM %s WHERE name = '%s'", BOARDTABLE, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	__id = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return __id;
}
function GetBoardNameByID(_id) {
	format(__string, 128, "SELECT name FROM %s WHERE ID_BOARD = %i", BOARDTABLE, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}
function GetBoardIDByName(_name[]) {
	new __id;
    format(__string, 128, "SELECT ID_BOARD FROM %s WHERE name = '%s'", BOARDTABLE, _name);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	__id = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return __id;
}
function GetCategoryIDByName(_name[]) {
	new __id;
    format(__string, 128, "SELECT ID_CAT FROM %s WHERE name = '%s'", CATEGORYTABLE, _name);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	__id = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return __id;
}
function GetCategoryNameByID(_id) {
	format(__string, 128, "SELECT name FROM %s WHERE ID_CAT = %i", CATEGORYTABLE, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}
function GetForumNews() {
	format(__string, 128, "SELECT news FROM %s", SETTINGSTABLE);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}
function GetForumSMTP_Username() {
	format(__string, 128, "SELECT smtp_username FROM %s", SETTINGSTABLE);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}
function GetForumSMTP_Port() {
	new _Port;
    format(__string, 128, "SELECT smtp_port FROM %s", SETTINGSTABLE);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	_Port = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return _Port;
}
//===============================[Member data]=================================

function GetMemberIP2ByID(_id, bool:_RealName) {
    FormatRealName(_RealName, "memberIP2", __string, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberIP2ByName(_name[], bool:_RealName) {
    FormatRealName(_RealName, "memberIP2", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberIPByID(_id, bool:_RealName) {
    FormatRealName(_RealName, "memberIP", __string, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberIPByName(_name[], bool:_RealName) {
    FormatRealName(_RealName, "memberIP", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberEmailByID(_id, bool:_RealName) {
    FormatRealName(_RealName, "emailAddress", __string, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberEmailByName(_name[], bool:_RealName) {
    FormatRealName(_RealName, "emailAddress", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberUMessagesByID(_id, bool:_RealName) {
    FormatRealName(_RealName, "unreadMessages", __string, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[unreadMessages] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[unreadMessages];
}

function GetMemberUMessagesByName(_name[], bool:_RealName) {
    FormatRealName(_RealName, "unreadMessages", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[unreadMessages] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[unreadMessages];
}

function GetMemberGroupByID(_id, bool:_RealName) {
    FormatRealName(_RealName, "ID_GROUP", __string, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[ID_GROUP] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[ID_GROUP];
}

function GetMemberGroupByName(_name[], bool:_RealName) {
    FormatRealName(_RealName, "ID_GROUP", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[posts] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[posts];
}

function GetMemberPostsByID(_id, bool:_RealName) {
    FormatRealName(_RealName, "posts", __string, _id);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[posts] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[posts];
}
	
function GetMemberPostsByName(_name[], bool:_RealName) {
    FormatRealName(_RealName, "posts", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[posts] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[posts];
}

function GetMemberNameByID(_id, bool:_RealName)
{
	if(_RealName == false) {
		format(__string, 128, "SELECT memberName FROM %s WHERE ID_MEMBER=%d", MEMBERTABLE, _id);
	}
	else {
	    format(__string, 128, "SELECT realName FROM %s WHERE ID_MEMBER=%d", MEMBERTABLE, _id);
	}
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if (!mysql_num_rows(SMFConnection)) return __blank;
	mysql_fetch_row_format(__string, "|", SMFConnection);
   	mysql_free_result(SMFConnection);
   	return __string;
}

function GetMemberIDByName(_name[], bool:_RealName) {
	FormatRealName(_RealName, "ID_MEMBER", _name, -1);
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
    if(mysql_num_rows(SMFConnection) == 0) return 0;
	SMFMemberData[ID_MEMBER] = mysql_fetch_int(SMFConnection);
	mysql_free_result(SMFConnection);
	return SMFMemberData[ID_MEMBER];
}

function CheckUserNameAndPassword(_name[], Password__[], bool:_RealName) {
	new hash[60];
	#pragma unused Password__
 	strmid(hash, _name, 0, strlen(_name), sizeof hash);
 	strins(hash, _name, 0, sizeof hash);
 	for(new s; s < strlen(hash); s++) hash[s] = tolower(hash[s]);
    if(_RealName == false) {
		format(__string, 128, "SELECT * FROM %s WHERE memberName='%s' AND passwd = sha1('%s')", MEMBERTABLE, _name,hash);
	}
	else {
	    format(__string, 128, "SELECT * FROM %s WHERE realName='%s' AND passwd = sha1('%s')", MEMBERTABLE, _name,hash);
	}
	mysql_query(__string, -1, -1, SMFConnection);
	mysql_store_result(SMFConnection);
	if(mysql_num_rows(SMFConnection) == 0) {
	    mysql_free_result();
	    return 0;
	}
	else {
	    mysql_free_result();
		return 1;
	}
}
//===============================[======]=================================

function OnCSMFInit() {
	mysql_debug(1);
	print("Connecting to the database - This make take a while!");
	SMFConnection = mysql_connect(SMF_HOST, SMF_USER, SMF_DB, SMF_PASSWORD);
	if(mysql_ping(SMFConnection) != 1) {
	    print("Unable to connect");
	}
	else {
	    print("Connected to the CSMF");
	}
}

function FormatRealName(bool:_RealName, _field[], _name[], _id) {
	mysql_real_escape_string(_field, __Escape[0], SMFConnection);
	mysql_real_escape_string(_name, __Escape[1], SMFConnection);
	if(_id == -1) {
	    if(_RealName == false) {
			format(__string, 128, "SELECT %s FROM %s WHERE memberName = '%s'", __Escape[0], MEMBERTABLE, __Escape[1]);
		}
		else {
		    format(__string, 128, "SELECT %s FROM %s WHERE realName = '%s'", __Escape[0], MEMBERTABLE, __Escape[1]);
		}
	}
	else {
 		format(__string, 128, "SELECT %s FROM %s WHERE ID_MEMBER = %d", __Escape[0], MEMBERTABLE, _id);
	}
}
