#include <iostream>
#include <vector>

using namespace std;

struct malaltia {
    double pm = 0;
    int pt = 0;
    string diagnostic;
    string solucio;
};

int main () {

    malaltia insuficiencia;
    insuficiencia.pt = 8;
    insuficiencia.diagnostic = "Angiografia coronaria +, anàlisi de sang, ecocardiograma";
    insuficiencia.solucio = "Diurètics (consultar altres MPI per si no són compatibles)";

    malaltia trombolisme;
    trombolisme.pt = 7;
    trombolisme.diagnostic = "Angiotomografia de tòrax + i/o arteriografia";
    trombolisme.solucio = "Heparina/acenocumarol (consultar MPIs i compatibilitat), tractament fibronolític (si és molt severa)";
    
    malaltia toxics;
    toxics.pt = 11;
    toxics.diagnostic = "Probes d'imatges de pulmons +, anàlisi de sang, Endoscòpia (consultar compatibilitat amb altres MPIs)";
    toxics.solucio = "Teràpia d'oxigen";

    malaltia refluxe;
// falta de ferro com a prova també
    refluxe.pt = 9;
    refluxe.diagnostic = "PHmetria amb impedància +, nanometria esofàgica d'alta resolució, comprovar nivalls de ferro en sang";
    refluxe.solucio = "No fumar / beure, perdre pes (en cas de sobrepes), Funduplicatura total/parcial (consultar compatibilitat amb altres MPIs)";

    malaltia abdomen;
    abdomen.pt = 10;
    abdomen.diagnostic = "Hemograma+, probes de funció hepà tica i renal";
    abdomen.solucio = "líquids intravenosos +, intervenció quirúrgica (consultar compatibilitat amb altres MPIs)";
    
    malaltia pneumotorax;
    pneumotorax.pt = 7;
    pneumotorax.diagnostic = "radiografia de tòrax +, TAC (en cas que s'hagi tingut abans (consultar compatibilitat amb altrs MPIs))";
    pneumotorax.solucio = "drenar l'aire +, connectar a l'aspiració durant unes hores";

    malaltia contusio;
    contusio.pt = 5;
    contusio.diagnostic = "radiografia de tòrax+, mesurar oxigen en sang (pulsioxímetre)";
    contusio.solucio = "Oxigenoteràpia amb ventilació mecànica +, Analgèsics (consultar compatibilitat amb altres MPIs) ";

    malaltia exacerbacio;
    exacerbacio.pt =  7;
    exacerbacio.diagnostic = "Examen de sang, broncoscòpia +, ressonància magnètica del tòrax";
    exacerbacio.solucio = "En cas de tenir nivell d'oxigen en sang baix fer oxigenoteràpia, altrament fer rehabilitació pulmonar";

    
    bool fatiga = 0;
    bool bategs = 0;
    bool inflamacio = 1;
    bool augment_de_pes = 0;
    bool mal_pit = 0;
    bool tosir_sang = 0;
    bool respiracio_accelerada = 0;
    bool febre = 1;
    bool convulsions = 0;
    bool mal_de_cap = 0;
    bool nausees = 0;
    bool somnolencia = 0;
    bool tos = 1;
    bool mal_de_traquea = 1;
    bool mal_als_pulmons = 0;
    bool confusio = 0;
    bool mucosa_irritada = 0;
    bool acidesa = 1;
    bool sagnat_digestiu = 0;
    bool vomit_persistent = 1;
    bool perdua_de_pes = 0;
    bool taquicardia = 1;
    bool ictericia = 0;
    bool sang_orina = 0;
    bool dolor_toracic = 1;
    bool falta_aire = 1;
    bool tos_seca = 0;
    bool xiuleig_al_respirar = 1;
    bool coloritzacio_blavosa  = 0;

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

    struct sticbe{
        double p;
        string qpasa;
        string morire;
        string ahoraque;
    };
    vector <sticbe> probs (8);

    probs [0].p = insuficiencia.pm;
    probs [0].qpasa = "Insuficiencia Cardíaca";
    probs [0].morire = insuficiencia.diagnostic;
    probs [0].ahoraque = insuficiencia.solucio;
    probs [1].p = trombolisme.pm;
    probs [1].qpasa = "Trombolisme Pulmonar";
    probs [1].morire = trombolisme.diagnostic;
    probs [1].ahoraque = trombolisme.solucio;
    probs [2].p = toxics.pm;
    probs [2].qpasa = "Inhalació de Toxics Pulmonars";
    probs [2].morire = toxics.diagnostic;
    probs [2].ahoraque = toxics.solucio;
    probs [3].p = refluxe.pm;
    probs [3].qpasa = "Refluxe Gastroesofàgic";
    probs [3].morire = refluxe.diagnostic;
    probs [3].ahoraque = refluxe.solucio;
    probs [4].p = abdomen.pm;
    probs [4].qpasa = "Abdomen Agut";
    probs [4].morire = abdomen.diagnostic;
    probs [4].ahoraque = abdomen.solucio;
    probs [5].p = pneumotorax.pm;
    probs [5].qpasa = "Pneumotòrax";
    probs [5].morire = pneumotorax.diagnostic;
    probs [5].ahoraque = pneumotorax.solucio;
    probs [6].p = contusio.pm;
    probs [6].qpasa = "Contusió Pulmonar";
    probs [6].morire = contusio.diagnostic;
    probs [6].ahoraque = contusio.solucio;
    probs [7].p = exacerbacio.pm;
    probs [7].qpasa = "Exacerbació Aguda";
    probs [7].morire = exacerbacio.diagnostic;
    probs [7].ahoraque = exacerbacio.solucio;

    bool acabacio = 1;
    while(acabacio){
        for(int i = 1; i<probs.size(); i++){
            if(probs[i-1].p > probs[i].p){
                swap(probs[i-1],probs[i]);
                acabacio = 0;
            }
        }
        if(not acabacio) acabacio = 1;
        else acabacio = 0;
    }

    for(int i = 7; i>4; i--){
        cout<<probs[i].qpasa<<" "<<probs[i].p<<endl<<"Proves a fer: "<<probs[i].morire<<endl<<"Tractament: "<<probs[i].ahoraque<<endl;
    }
}