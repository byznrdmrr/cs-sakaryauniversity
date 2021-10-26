#include "fields.h"
#include "program.h"

int main(int narg, char* argv[]){
        if( narg != 4)
        {
                printf("Eksik veya fazla parametre girdiniz.\n");
                return 0;
                
        }
        
        FILE *file = fopen ("soru2-replace.txt","w");
        IS is = new_inputstruct(argv[1]);
        if (is == NULL) {
                printf("Dosya bulunamadi!\n");
                return 0;
        }
        int i, toplam=0;
        while(get_line(is) >= 0) {
                for (i = 0; i < is->NF; i++) {
                        if(strcmp(argv[2],is->fields[i]))
                        {
                                fprintf(file,"%s ",is->fields[i]); 
                        }
                        else
                        {
                                fprintf(file,"%s ",argv[3]); 
                                toplam++;
                        }
                        
                }
                fprintf(file,"\n");
        }

        if(toplam > 0){
                printf("Toplam degisen kelime sayisi: %d\n",toplam);
        }
        else{
                printf("Aradiginiz kelime metin belgesinde bulunamadi.\n");
        }
                


        
        return 0;
}