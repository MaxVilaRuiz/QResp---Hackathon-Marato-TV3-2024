#include <iostream>
#include <vector>

using namespace std;

struct malaltia {
    double pm = 0;
    int pt =0;
    string diagnostic;
};

int main () {

    malaltia insuficiencia;
    insuficiencia.pt = 8;


    malaltia trombolisme;
    trombolisme.pt = 7;

    malaltia toxics;
    toxics.pt = 11;

    malaltia refluxe;
// falta de ferro com a prova també
    refluxe.pt = 9;

    malaltia abdomen;
    abdomen.pt = 10;

    malaltia pneumotorax;
    pneumotorax.pt = 7;

    malaltia contusio;
    contusio.pt = 5;

    malaltia exacerbacio;
    exacerbacio.pt =  7;

    
    bool fatiga = 0;
    bool bategs = 0;
    bool inflamacio = 0;
    bool augment_de_pes = 0;
    bool mal_pit = 0;
    bool tosir_sang = 0;
    bool respiracio_accelerada = 0;
    bool febre = 0;
    bool convulsions = 0;
    bool mal_de_cap = 0;
    bool nausees = 0;
    bool somnolencia = 0;
    bool tos = 0;
    bool mal_de_traquea = 0;
    bool mal_als_pulmons = 0;
    bool confusio = 0;
    bool mucosa_irritada = 0;
    bool acidesa = 0;
    bool sagnat_digestiu = 0;
    bool vomit_persistent = 0;
    bool perdua_de_pes = 0;
    bool taquicardia = 0;
    bool ictericia = 0;
    bool sang_orina = 0;
    bool dolor_toracic = 0;
    bool falta_aire = 0;
    bool tos_seca = 0;
    bool xiuleig_al_respirar = 0;
    bool coloritzacio_blavosa  = 0;

    string malaltia;

    if( fatiga ){
        insuficiencia.pm += 1;
    }
    if( bategs ){
        insuficiencia.pm += 2;
    }
    if( inflamacio ){
        insuficiencia.pm += 2;
    }
    if( augment_de_pes ){
        insuficiencia.pm += 3;
    }
    if( mal_pit ){
        trombolisme.pm += 1;
    }
    if( tosir_sang ){
        trombolisme.pm += 2;
        abdomen.pm += 2;
    }
    if( respiracio_accelerada ){
        trombolisme.pm += 1;
    }
    if( febre ){
        trombolisme.pm += 1;
        exacerbacio.pm += 1;
    }
    if( convulsions ){
        trombolisme.pm += 2;
    }
    if( mal_de_cap ){
        toxics.pm += 1;
    }
    if( nausees ){
        toxics.pm += 1;
        contusio.pm += 1;
    }
    if( somnolencia ){
        toxics.pm += 3;
    }
    if( tos ){
        toxics.pm += 1;
        exacerbacio.pm += 1;
    }
    if( mal_de_traquea ){
        toxics.pm += 2;
    }
    if( mal_als_pulmons ){
        toxics.pm += 2;
    }
    if( confusio ){
        toxics.pm += 1;
    }
    if( mucosa_irritada ){
        refluxe.pm += 3;
    }
    if( acidesa ){
        refluxe.pm += 1;
    }
    if( sagnat_digestiu ){
        refluxe.pm += 2;
        abdomen.pm += 2;
        if(tosir_sang)abdomen.pm ++;
    }
    if( vomit_persistent ){
        refluxe.pm += 2;
    }
    if( perdua_de_pes ){
        refluxe.pm += 1;
    }
    if( taquicardia ){
        abdomen.pm += 1;
    }
    if( ictericia ){
        abdomen.pm += 2;
    }
    if( sang_orina ){
        abdomen.pm += 3;
        if(tosir_sang and sagnat_digestiu and abdomen.pm < abdomen.pt) abdomen.pm ++; 
        else if (tosir_sang and not sagnat_digestiu) abdomen.pm ++;
        else if (not tosir_sang and sagnat_digestiu) abdomen.pm++;    
    }
    if( dolor_toracic ){
        pneumotorax.pm += 2;
        contusio.pm += 2;
    }
    if( falta_aire ){
        pneumotorax.pm += 2;
        contusio.pm += 2;
        exacerbacio.pm += 2;
        if(dolor_toracic and (not tos_seca and not xiuleig_al_respirar)){
            pneumotorax.pm += 2;  
        }
        else if(dolor_toracic and (not tos_seca or not xiuleig_al_respirar)){
            pneumotorax.pm ++;
        }
    }
    if( tos_seca ){
        pneumotorax.pm += 2;
    }
    if( xiuleig_al_respirar ){
        pneumotorax.pm += 1;
    }
    if( coloritzacio_blavosa ){
        exacerbacio.pm += 3;
    }

    insuficiencia.pm /= insuficiencia.pt;
    trombolisme.pm /= trombolisme.pt;
    toxics.pm /= toxics.pt;
    refluxe.pm /= refluxe.pt;
    abdomen.pm /= abdomen.pt;
    pneumotorax.pm /= pneumotorax.pt;
    contusio.pm /= contusio.pt;
    exacerbacio.pm /= exacerbacio.pt;

}