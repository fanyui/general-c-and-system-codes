#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HASHSIZE 101
//list structure
struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtable[HASHSIZE];
unsigned hash1(char *);//hash function prototype
struct nlist *install_lookup(char *,char *);

struct nlist *lookup1(char *);

int main(){
	struct nlist *harisu_test,*lukuptest,me;
	int input;
	char *har,*definition;
	printf("%d\n",hash1("school"));
		printf("name definition\n");
		scanf("%d",&input);
		printf("%d",input);
		scanf("%s",&har);
		printf("%s",har);
		harisu_test=install_lookup(har,definition);

	return 0;
}



unsigned hash1(char *s){

	unsigned hash_value;
	for(hash_value=0;*s != '\0';s++)
		hash_value += *s + 31 ;
	return hash_value % HASHSIZE;

}

struct nlist *lookup1(char *s){

	struct nlist *np;
	unsigned num=hash1(s);
	printf("lookup hash is %d",num);
	np=hashtable[num];
	printf("%d",*np);
	for ( ;np != NULL;np=np->next)
		if(strcmp(np->name,s)==0)
			return np;
		else 
			//printf("lookup suceeded\n");
			return NULL;
	if(np==NULL)
	return NULL;
	
}

struct nlist *install_lookup(char *name,char *definition){
	unsigned hashvalue;
	struct nlist *np;
	printf("malloc failed 1\n");
	np=lookup1(name);
	printf("lookup succeeded\n");
	if(np==NULL){
		printf("malloc is not working");
		np=(struct nlist *)malloc(sizeof(*np));
		printf("malloc failed 2\n");
		if(np==NULL|| (np->name=strdup(name))==NULL){
			//printf("malloc failed\n");
			return NULL;

		}
		hashvalue=hash1(name);
		np->next = hashtable[hashvalue];
		hashtable[hashvalue] = np;
	} else
/* already there */
		free((void *) np->defn);
/*free previous defn */
		if ((np->defn = strdup(definition)) == NULL)
		return NULL;
		return np;
}