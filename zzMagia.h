//questo file è un sacco disordinato, fossi in te non ci metterei le mani e salterei in fondo


// TODO stampa la lista numerica degli id
	int idsMazzo[16];
	int lnIdsMazzo=0;
	int base=64;
	int PrecCard=-1;
	int cont=0;
	int idAnalizzata=commander->m_id;
	char r_value;
	char l_value;
	char ret[64];
	int lnRet=0;
	strcpy(ret,"");
	
	idsMazzo[lnIdsMazzo++]=commander->m_id;
	
	for(const Card* card: cards) if(card->m_id!=1) idsMazzo[lnIdsMazzo++]=card->m_id;
	
	for(int i=0;i<lnIdsMazzo;i++)
	{
		idAnalizzata=idsMazzo[i];
		
		if(idAnalizzata != PrecCard)
		{
			if(cont!=0)
			{
				l_value='+';
				r_value=104+cont;
				cont=0;
			}
			l_value=idAnalizzata/base;
			r_value=idAnalizzata%base;
			if(l_value>=0 and l_value<=25) l_value='A'+l_value;
			else if(l_value>=26 and l_value<=51) l_value='a'+l_value-26;
			else if(l_value>=52 and l_value<=61) l_value='0'+l_value-52;
			else if(l_value==62) l_value='+';
			else if(l_value==63) l_value='/';
			if(r_value>=0 and r_value<=25) r_value='A'+r_value;
			else if(r_value>=26 and r_value<=51) r_value='a'+r_value-26;
			else if(r_value>=52 and r_value<=61) r_value='0'+r_value-52;
			else if(r_value==62) r_value='+';
			else if(r_value==63) r_value='/';
			ret[lnRet]=l_value;
			ret[lnRet+1]=r_value;
			lnRet+=2;
		}
		else cont+=1;
		PrecCard=idAnalizzata;
		if(cont!=0)
		{
			l_value='+';
			r_value=104+cont;
			cont=0;
			ret[lnRet]=l_value;
			ret[lnRet+1]=r_value;
			lnRet+=2;
		}
	}
	ret[lnRet]='\0';
	//std::cout <<"\nHash del deck: " << ret << "\n";
	//TODO leggere ORIGINALsaved_decks.txt e costruire la nuova riga in base a quello che c'è lì, per ridurre al minimo le modifiche.
	
	FILE *out;
	out=fopen("saved_decks.txt","w");
	fprintf(out,"{\n\"8\":{\"name\":\"Conquest\",\"cards\":\"%s\"}\n}",ret);
	fclose(out);
#ifndef FUNZIONI_DICHIARABILI
#define FUNZIONI_DICHIARABILI
}

void dummy()
{

#endif