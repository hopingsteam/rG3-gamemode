stock IsARolePlayName(name[])
{
	new
				szLastCell,
		bool: 	bUnderScore;
		
	for(new i; i < strlen(name); i++)
	{
		if(name[i] == '_')
		{
			if(bUnderScore == true)
			{
				return 0;
			}
			
			bUnderScore = true;
		}
		
		else if(!szLastCell || szLastCell == '_') // Check if capitalized where it should be
		{
			if(name[i] < 'A' || name[i] > 'Z')
			{
				return 0;
			}
		}
		
		else
		{
			if(name[i] < 'a' || name[i] > 'z')
				return 0;
		}
		
		szLastCell = name[i];
	}
	
	if(bUnderScore == false)
		return 0;
		
	return 1;
}