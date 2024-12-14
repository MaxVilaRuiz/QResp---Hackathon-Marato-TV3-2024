#include <iostream>
#include <vector>

using namespace std;

struct malaltia {
    string s1 = "res";
    int p1 = 0;
    string s2 = "res";
    int p2 = 0;
    string s3 = "res";
    int p3 = 0;
    string s4 = "res";
    int p4 = 0;
    string s5 = "res";
    int p5 = 0;
    string s6 = "res";
    int p6 = 0;
    string s7 = "res";    
    int p7 = 0;
    int pt =0;
};



int main () {
    malaltia insuficiencia;

    insuficiencia.s1 = "fatiga";
    insuficiencia.p1 = 1;
    insuficiencia.s2 = "bategs";
    insuficiencia.p2 = 2;
    insuficiencia.s3 = "inflamacio";
    insuficiencia.p3 = 2;
    insuficiencia.s4 = "augment_de_pes";
    insuficiencia.p4 = 3;

    malaltia trombolisme;

    trombolisme.s1 = "mal_de_pit";
    trombolisme.p1 = 1;
    trombolisme.s2 = "tosir_sang";
    trombolisme.p2 = 2;
    trombolisme.s3 = "respiracio_accelerada";
    trombolisme.p3 = 1;
    trombolisme.s4 = "febre";
    trombolisme.p4 = 1;
    trombolisme.s5 = "convulsions";
    trombolisme.p5 = 2;

    malaltia toxics;

    toxics.s1 = "mal_de_cap";
    toxics.p1 = 1;
    toxics.s2 = "nausees";
    toxics.p2 = 1;
    toxics.s3 = "somnolencia";
    toxics.p3 = 3;
    toxics.s4 = "tos";
    toxics.p4 = 1;
    toxics.s5 = "mal_de_traquea";
    toxics.p5 = 2;
    toxics.s6 = "mal_als_pulmons";
    toxics.p6 = 3;
    toxics.s7 = "confusio";
    toxics.p7 = 1;

    malaltia refluxe;
// falta de ferro com a prova també
    refluxe.s1 = "mucosa_irritada";
    refluxe.p1 = 3;
    refluxe.s2 = "acidesa";
    refluxe.p2 = 1;
    refluxe.s3 = "sagnat_digestiu";
    refluxe.p3 = 2;
    refluxe.s4 = "vòmit_persistent";
    refluxe.p4 = 2;
    refluxe.s4 = "perdua_de_pes";
    refluxe.p4 = 1;

    malaltia abdomen;
// fer algo amb tosir cagar i pixar sang
    abdomen.s1 = "taquicardia";
    abdomen.p1 = 1;
    abdomen.s2 = "ictericia";
    abdomen.p2 = 2;
    abdomen.s3 = "tosir_sang";
    abdomen.p3 = 2;
    abdomen.s4 = "sang_orina";
    abdomen.p4 = 3;
    abdomen.s5 = "sagnat_digestiu";
    abdomen.p5 = 2;

    malaltia pneumotorax;
    // dolor toracic + falta d'aire = combo wombo
    pneumotorax.s1 = "dolor_toracic";
    pneumotorax.p1 = 2;
    pneumotorax.s2 = "falta_aire";
    pneumotorax.p2 = 2;
    pneumotorax.s3 = "tos_seca";
    pneumotorax.p3 = 2;
    pneumotorax.s4 = "xiuleig_al_respirar";
    pneumotorax.p4 = 1;


    malaltia contusio;
    // va lligada amb el pneumotorax, pensa q coño fer
    contusio.s1 = "nausees";
    contusio.p1 = 1;
    contusio.s2 = "falta_aire";
    contusio.p2 = 2;
    contusio.s4 = "dolor_toracic";
    contusio.p4 = 2;

    malaltia exacerbacio;

    exacerbacio.s1 = "falta_aire";
    exacerbacio.p1 =  2;
    exacerbacio.s2 = "coloritzacio_blavosa";
    exacerbacio.p2 =  3;
    exacerbacio.s3 = "tos";
    exacerbacio.p3 =  1;
    exacerbacio.s4 = "febre";
    exacerbacio.p4 =  1;



}