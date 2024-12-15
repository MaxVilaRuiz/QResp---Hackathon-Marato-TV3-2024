#include <iostream>
#include <vector>

using namespace std;

struct malaltia {
    double pm = 0;
    int pt =0;
    string diagnostic;
    string solucio;
};

int main () {

    malaltia pneumonia;
    pneumonia.pt = 8;
    pneumonia.diagnostic = "Radiografia del tòrax, probes per veure la presència d'altres gèrmens";

    malaltia insuficiencia;
    insuficiencia.pt = 8;
    insuficiencia.diagnostic = "Angiografia coronaria +, anàlisi de sang, ecocardiograma";
    insuficiencia.solucio = "Diurètics (consultar compatibilitat amb altres MPIs)";

    malaltia trombolisme;
    trombolisme.pt = 8;
    trombolisme.diagnostic = "Angiotomografia de tòrax + i/o arteriografia";
    trombolisme.solucio = "Heparina/acenocumarol (consultar compatibilitat amb altres MPIs), tractament fibronolític (si és molt severa)";
    
    malaltia toxics;
    toxics.pt = 11;
    toxics.diagnostic = "Probes d'imatges de pulmons +, anàlisi de sang, Endoscòpia (consultar compatibilitat amb altres MPIs)";
    toxics.solucio = "Teràpia d'oxigen";

    malaltia refluxe;
    refluxe.pt = 9;
    refluxe.diagnostic = "PHmetria amb impedància +, nanometria esofàgica d'alta resolució, comprovar nivalls de ferro en sang";
    refluxe.solucio = "No fumar / beure, perdre pes (en cas de sobrepes), Funduplicatura total/parcial (consultar compatibilitat amb altres MPIs)";

    malaltia abdomen;
    abdomen.pt = 10;
    abdomen.diagnostic = "Hemograma+, probes de funció hepàtica i renal";
    abdomen.solucio = "Líquids intravenosos +, intervenció quirúrgica (consultar compatibilitat amb altres MPIs)";
    
    malaltia pneumotorax;
    pneumotorax.pt = 7;
    pneumotorax.diagnostic = "Radiografia de tòrax +, TAC (en cas que s'hagi tingut abans (consultar compatibilitat amb altrs MPIs))";
    pneumotorax.solucio = "Drenar l'aire +, connectar a l'aspiració durant unes hores";

    malaltia contusio;
    contusio.pt = 5;
    contusio.diagnostic = "Radiografia de tòrax+, mesurar oxigen en sang (pulsioxímetre)";
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
    bool temperatura_baixa = 0;

    if( fatiga ){
        insuficiencia.pm += 1;
        pneumonia.pm += 1;
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
        trombolisme.pm += 2;
        pneumonia.pm += 2;
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
        pneumonia.pm +=1;
    }
    if( somnolencia ){
        toxics.pm += 3;
    }
    if( tos ){
        toxics.pm += 1;
        exacerbacio.pm += 1;
        pneumonia.pm += 1;
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
    if(temperatura_baixa){
        pneumonia.pm += 3;
    }

    insuficiencia.pm /= insuficiencia.pt;
    trombolisme.pm /= trombolisme.pt;
    toxics.pm /= toxics.pt;
    refluxe.pm /= refluxe.pt;
    abdomen.pm /= abdomen.pt;
    pneumotorax.pm /= pneumotorax.pt;
    contusio.pm /= contusio.pt;
    exacerbacio.pm /= exacerbacio.pt;
    pneumonia.pm /= pneumonia.pt;

    struct sticbe{
        double p;
        string qpasa;
        string morire;
        string ahoraque;
    };
    vector <sticbe> probs (9);

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
    probs [8].p = pneumonia.pm;
    probs [8].qpasa = "Pneumonia";
    probs [8].morire = pneumonia.diagnostic;
    probs [8].ahoraque = pneumonia.solucio;

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

    for(int i = 8; i>5; i--){
        if(probs [i].qpasa == "Pneumonia"){
            cout<<probs[i].qpasa<<" "<<probs[i].p<<endl<<"Proves a fer: "<<probs[i].morire<<endl<<"Tractament per pacients Immunosuprimits:"<<endl;
            cout<<"Si PCR + : Oseltamivir: 75 mg cada 12 hores per via oral."<<endl;
            cout<<"Si hi ha infecció bacteriana: Piperacilina/Tazobactam: 4 g/0,5 g cada 8 hores intravenós. ";
            cout<<"Altrament: Cefalosporina 3ª generació + Levofloxacina: 500 mg cada 24 hores."<<endl;
            cout<<"Si se sospita de CMV: Ganciclovir: 5 mg/kg cada 12 hores intravenós."<<endl;
            cout<<"Si se sospita pneumonia per fongs: Sulfametoxazol/Trimetoprim: 800/160 mg cada 12 hores via oral, afegir àcid fòlic"<<endl<<endl;
            cout<<"Tractament per pacients Immunocompetents: "<<endl;
            cout<<"Si PCR + : Administrar HBPM (Heparina de Baix Peso Molecular): 0,5-0,9 mL segons el pes corporal."<<endl;
            cout<<"Si Metilprednisolona: En casos específicos, administrar ½-1 mg/kg/día intravenoso.a infecció bacteriana: Cefalosporina 3ª generació + Levofloxacina: 500 mg cada 24 hores. "<<endl<<endl;

        }
        else
        cout<<probs[i].qpasa<<" "<<probs[i].p<<endl<<"Proves a fer: "<<probs[i].morire<<endl<<"Tractament: "<<probs[i].ahoraque<<endl<<endl;
    }
    cout<<"Aquest és un suport general en cas de ser necessàri (consultar compatibilitat amb altres MPIs):"<<endl<<"Oxigenoterapia: Ajustada segons saturació d'oxígen (mantenir SatO2 ≥ 92%)."<<endl;
    cout<<"N-Acetilcisteína (antioxidant): 600 mg cada 8 hores via oral."<<endl<<"Morfina: 2,5-5 mg subcutània per aliviar el dolor en casos de disnea intensa."<<endl;
    cout<<"Metilprednisolona: En casos específics, administrar ½-1 mg/kg/dia intravenós."<<endl<<"Vitamina D y calci: Suplementació en cas de mal alveolar."<<endl;
    cout<<"Inhibidors de bomba de protons (IBP): Omeprazol 20 mg al dia."<<endl;
}