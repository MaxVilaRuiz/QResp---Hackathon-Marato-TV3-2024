document.getElementById('btn1').addEventListener('click', function(event) {
    event.preventDefault();
    document.getElementById('btn1').style.display = 'none';
    document.getElementById('btn2').style.display = 'block';
})

document.getElementById('btn2').addEventListener('click', function(event) {
    event.preventDefault();
    document.getElementById('btn2').style.display = 'none';
    document.getElementById('btn1').style.display = 'block';

    let fatiga = document.getElementById('fatiga').checked;
    let bategs = document.getElementById('bategs').checked;
    let inflamacio = document.getElementById('inflamacio').checked;
    let augment_de_pes = document.getElementById('augment_de_pes').checked;
    let mal_pit = document.getElementById('mal_pit').checked;
    let tosir_sang = document.getElementById('tosir_sang').checked;
    let respiracio_accelerada = document.getElementById('respiracio_accelerada').checked;
    let febre = document.getElementById('febre').checked;
    let convulsions = document.getElementById('convulsions').checked;
    let somnolencia = document.getElementById('somnolencia').checked;
    let tos = document.getElementById('tos').checked;
    let mal_de_traquea = document.getElementById('mal_de_traquea').checked;
    let mal_als_pulmons = document.getElementById('mal_als_pulmons').checked;
    let confusio = document.getElementById('confusio').checked;
    let mucosa_irritada = document.getElementById('mucosa_irritada').checked;
    let acidesa = document.getElementById('acidesa').checked;
    let sagnat_digestiu = document.getElementById('sagnat_digestiu').checked;
    let vomit_persistent = document.getElementById('vomit_persistent').checked;
    let perdua_de_pes = document.getElementById('perdua_de_pes').checked;
    let taquicardia = document.getElementById('taquicardia').checked;
    let ictericia = document.getElementById('ictericia').checked;
    let dolor_toracic = document.getElementById('dolor_toracic').checked;
    let sang_orina = document.getElementById('sang_orina').checked;
    let falta_aire = document.getElementById('falta_aire').checked;
    let tos_seca = document.getElementById('tos_seca').checked;
    let xiuleig_al_respirar = document.getElementById('xiuleig_al_respirar').checked;
    let coloritzacio_blavosa = document.getElementById('coloritzacio_blavosa').checked;
    let mal_cap = document.getElementById('mal_cap').checked;
    let nausees = document.getElementById('nausees').checked;
    let temp_baixa = document.getElementById('temp_baixa').checked;

    let simptomes = [];
    if (fatiga) {
        simptomes.push("fatiga")
    }
    if (bategs) {
        simptomes.push("bategs")
    }
    if (inflamacio) {
        simptomes.push("fatiinflamacioga")
    }
    if (augment_de_pes) {
        simptomes.push("augment_de_pes")
    }
    if (mal_pit) {
        simptomes.push("mal_pit")
    }
    if (tosir_sang) {
        simptomes.push("tosir_sang")
    }
    if (respiracio_accelerada) {
        simptomes.push("respiracio_accelerada")
    }
    if (febre) {
        simptomes.push("febre")
    }
    if (convulsions) {
        simptomes.push("convulsions")
    }
    if (somnolencia) {
        simptomes.push("somnolencia")
    }
    if (tos) {
        simptomes.push("tos")
    }
    if (mal_de_traquea) {
        simptomes.push("mal_de_traquea")
    }
    if (mal_als_pulmons) {
        simptomes.push("mal_als_pulmons")
    }
    if (confusio) {
        simptomes.push("confusio")
    }
    if (mucosa_irritada) {
        simptomes.push("mucosa_irritada")
    }
    if (acidesa) {
        simptomes.push("acidesa")
    }
    if (vomit_persistent) {
        simptomes.push("vomit_persistent")
    }
    if (perdua_de_pes) {
        simptomes.push("perdua_de_pes")
    }
    if (taquicardia) {
        simptomes.push("taquicardia")
    }
    if (ictericia) {
        simptomes.push("ictericia")
    }
    if (dolor_toracic) {
        simptomes.push("dolor_toracic")
    }
    if (tos_seca) {
        simptomes.push("tos_seca")
    }
    if (xiuleig_al_respirar) {
        simptomes.push("xiuleig_al_respirar")
    }
    if (coloritzacio_blavosa) {
        simptomes.push("coloritzacio_blavosa")
    }
    if (mal_cap) {
        simptomes.push("mal_cap")
    }
    if (nausees) {
        simptomes.push("nausees")
    }
    if (temp_baixa) {
        simptomes.push("temp_baixa")
    }
});


// Posar el diagnòstic i tractament corresponents de la base de dades.
let diagnostic = document.getElementById('diagnostic');
diagnostic.innerHTML = "";
let tractament = document.getElementById('tractament');
tractament.innerHTML = "";
