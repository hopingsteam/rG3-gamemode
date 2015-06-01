/* Multi text lines include

   Version: 1.0
   Date: 2010-03-18
   Credits: KuHS

   What it do?
   It transfers string's text into two lines.

   What it used for?
   It's used for RolePlay servers. Basically most RP servers have /me /do /b commands.
   This function can transfer typed command text into multiple lines.
*/

#include <a_samp>

forward SendClientMessageA(playerid,color,text[]);

public SendClientMessageA(playerid,color,text[])
{
	new safetxt[256];
	format(safetxt,sizeof(safetxt),"%s",text);
	if(strlen(safetxt) <= 88) { SendClientMessage(playerid,color,text); }
	else {

	    new texts[128];
	    strmid(texts,safetxt,88,256);
   		strins(safetxt, "-", 88, 1);
		strdel(safetxt, 89, strlen(safetxt));
		SendClientMessage(playerid,color,safetxt);
		SendClientMessage(playerid,color,texts);

	}
}