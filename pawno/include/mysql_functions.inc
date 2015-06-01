/*

  ___ _____ _   _  _  ___  ___  ___  _     ___
 / __|_   _/_\ | \| |/ _ \| _ \/ _ \| |   / _ \
 \__ \ | |/ _ \| .` | (_) |  _/ (_) | |__| (_) |
 |___/ |_/_/ \_\_|\_|\___/|_|  \___/|____|\___/



*/

/*-----------------------------------------------------
* Name: Mysql Functions
* Version: 1.5
* Author: Joe Lewis (Joe) & TopAz Centuallas(TopAz)
* Last Update: 15/12/11
----------------------------------------------------0*/

/*
	v1.0
    native mysql_createaccount(Username[], Password[]);
	native mysql_createdataint(Table[], Field[], Value);
	native mysql_createdatastr(Table[], Field[], Value[]);
	native mysql_createdatafloat(Table[], Field[], Float:Value);
	native mysql_createdatabool(Table[], Field[], bool:Value);
	native mysql_setint(Table[], Name[], Field[], Value, Update[]);
	native mysql_setstr(Table[], Name[], Field[], Value[], Update[]);
	native mysql_setfloat(Table[], Name[], Field[], Float:Value, Update[]);
	native mysql_setbool(Table[], Name[], Field[], bool:Value, Update[]);

	v1.5
	native mysql_getint(Table[], Name[], Field[], Update[]);
	native mysql_getfloat(Table[], Name[], Field[], Update[]);
	native mysql_getstring(Table[], Name[], Field[], Update[]);
	native mysql_getbool(Table[], Name[], Field[], Update[]);
	native mysql_addcolumn(Table[], ColumnName[], DataType[]);
	native mysql_delcolumn(Table[], ColumnName[]);
	native mysql_rencolumn(Table[], OldColumnName[], NewColumnName[], DataType[]);
	native mysql_changedatatype(Table[], ColumnName[], NewDataType[]);
	native mysql_rentable(OldTableName[], NewTableName[]);
*/


//============= By Joe ==============//

new querystring[512];

stock mysql_createaccount(Username[], Password[])
{
	new Escape[3][64];

	mysql_real_escape_string(mysql_account_table, Escape[0]);
	mysql_real_escape_string(Username, Escape[1]);
	mysql_real_escape_string(Password, Escape[2]);

	format(querystring, sizeof(querystring), "INSERT INTO `%s` (`username`, `password`) VALUES ('%s', SHA1('%s'))", Escape[0], Escape[1], Escape[2]);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_createdataint(Table[], Field[], Value)
{
	new Escape[2][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);

	format(querystring, sizeof(querystring), "INSERT INTO `%s` (`%s`) VALUES (%s)", Escape[0], Escape[1], Value);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_createdatastr(Table[], Field[], Value[])
{
	new Escape[3][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Value, Escape[2]);

	format(querystring, sizeof(querystring), "INSERT INTO `%s` (`%s`) VALUES ('%s')", Escape[0], Escape[1], Escape[2]);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_createdatafloat(Table[], Field[], Float:Value)
{
	new Escape[2][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);

	format(querystring, sizeof(querystring), "INSERT INTO `%s` (`%s`) VALUES (%f)", Escape[0], Escape[1], Value);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_createdatabool(Table[], Field[], bool:Value)
{
	new Escape[2][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);

	switch(Value)
	{
	    case true:
	    {
   			format(querystring, sizeof(querystring), "INSERT INTO `%s` (`%s`) VALUES (true)", Escape[0], Escape[1]);
		}
		case false:
		{
		    format(querystring, sizeof(querystring), "INSERT INTO `%s` (`%s`) VALUES (false)", Escape[0], Escape[1]);
		}
	}

	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

// Setting

stock mysql_setint(Table[], Name[], Field[], Value, Update[])
{
	new Escape[4][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);

	format(querystring, sizeof(querystring), "UPDATE `%s` SET `%s` = %d WHERE `%s` = '%s'", Escape[0], Escape[1], Value, Escape[2], Escape[3]);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_setstr(Table[], Name[], Field[], Value[], Update[])
{
	new Escape[5][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);
	mysql_real_escape_string(Value, Escape[4]);

	format(querystring, sizeof(querystring), "UPDATE `%s` SET `%s` = '%s' WHERE `%s` = '%s'", Escape[0], Escape[1], Escape[4], Escape[2], Escape[3]);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_setfloat(Table[], Name[], Field[], Float:Value, Update[])
{
	new Escape[4][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);

	format(querystring, sizeof(querystring), "UPDATE `%s` SET `%s` = %f WHERE `%s` = '%s'", Escape[0], Escape[1], Value, Escape[2], Escape[3]);
	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

stock mysql_setbool(Table[], Name[], Field[], bool:Value, Update[])
{
	new Escape[4][64];

	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);

	switch(Value)
	{
		case true:
		{
			format(querystring, sizeof(querystring), "UPDATE `%s` SET `%s` = true WHERE `%s` = '%s'", Escape[0], Escape[1], Escape[2], Escape[3]);
		}
		case false:
		{
            format(querystring, sizeof(querystring), "UPDATE `%s` SET `%s` = false WHERE `%s` = '%s'", Escape[0], Escape[1], Escape[2], Escape[3]);
		}
	}

	mysql_query(querystring);
	mysql_free_result();
	return 1;
}

//====================================//



//============= By TopAz =============//

stock mysql_getint(Table[], Name[], Field[], Update[])
{
	new
		Escape[4][64],
		result
	;
	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);
	format(querystring, sizeof(querystring), "SELECT '%s' FROM '%s' WHERE '%s' = '%s'", Escape[1], Escape[0], Escape[2], Escape[3]);
    mysql_query(querystring);
    mysql_store_result();
    result = mysql_fetch_int();
	mysql_free_result();
	return result;
}

stock mysql_getfloat(Table[], Name[], Field[], Update[])
{
	new
		Escape[4][64],
		Float:result
	;
	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);
	format(querystring, sizeof(querystring), "SELECT '%s' FROM '%s' WHERE '%s' = '%s'", Escape[1], Escape[0], Escape[2], Escape[3]);
    mysql_query(querystring);
    mysql_store_result();
    mysql_fetch_float(result);
	mysql_free_result();
	return result;
}

stock mysql_getstring(Table[], Name[], Field[], Update[])
{
	new
		Escape[4][64]
	;
	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);
	format(querystring, sizeof(querystring), "SELECT '%s' FROM '%s' WHERE '%s' = '%s'", Escape[1], Escape[0], Escape[2], Escape[3]);
    mysql_query(querystring);
    mysql_store_result(); new result[256];
    if(mysql_fetch_row(result)) { mysql_free_result(); }
	return result;
}

stock mysql_getbool(Table[], Name[], Field[], Update[])
{
	new
		Escape[4][64],
		result
	;
	mysql_real_escape_string(Table, Escape[0]);
	mysql_real_escape_string(Field, Escape[1]);
	mysql_real_escape_string(Update, Escape[2]);
	mysql_real_escape_string(Name, Escape[3]);
	format(querystring, sizeof(querystring), "SELECT '%s' FROM '%s' WHERE '%s' = '%s'", Escape[1], Escape[0], Escape[2], Escape[3]);
    mysql_query(querystring);
    mysql_store_result();
    result = mysql_fetch_int();
	mysql_free_result();
	if(result)
	{
	    return true;
	}
	else
	{
	    return false;
	}
}


//Example: mysql_addcolumn("accounts", "newcolumn", "VARCHAR(25)");
stock mysql_addcolumn(Table[], ColumnName[], DataType[])
{
	format(querystring, sizeof(querystring), "ALTER TABLE '%s' ADD '%s' '%s'", Table, ColumnName, DataType);
	mysql_query(querystring);
	return 1;
}

//Example: mysql_delcolumn("accounts", "newcolumn");
stock mysql_delcolumn(Table[], ColumnName[])
{
	format(querystring, sizeof(querystring), "ALTER TABLE '%s' DROP COLUMN '%s'", Table, ColumnName);
	mysql_query(querystring);
	return 1;
}

//Example: mysql_rencolumn("accounts", "newcolumn", "brotha", "INT(11)");
stock mysql_rencolumn(Table[], OldColumnName[], NewColumnName[], DataType[])
{
    format(querystring, sizeof(querystring), "ALTER TABLE '%s' CHANGE '%s' '%s' '%s'", Table, OldColumnName, NewColumnName, DataType);
	mysql_query(querystring);
	return 1;
}

//Example: mysql_changedatatype("accounts", "brotha", "VARCHAR(45)");
stock mysql_changedatatype(Table[], ColumnName[], NewDataType[])
{
    format(querystring, sizeof(querystring), "ALTER TABLE '%s' ALTER COLUMN '%s' '%s'", Table, ColumnName, NewDataType);
	mysql_query(querystring);
	return 1;
}

//Example: mysql_rentable("accounts", "players");
stock mysql_rentable(OldTableName[], NewTableName[])
{
    format(querystring, sizeof(querystring), "ALTER TABLE '%s' RENAME TO '%s'", OldTableName, NewTableName);
	mysql_query(querystring);
	return 1;
}

//===================================//
