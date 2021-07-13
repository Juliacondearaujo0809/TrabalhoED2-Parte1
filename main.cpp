#include <fstream>
#include <string.h>
#include <stdio.h>
#include "Artist.h"
#include "Track.h"

using namespace std;
using std::string;

Artist* lerArquivoBinArtist(char *caminho, int opcao) {
    Artist artist;

    char origem[100];
    strcpy(origem, caminho);
    strcat(origem, "/artists.bin");

    std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

    int quantidade;
    if (opcao == 2) {
        quantidade = 100;
    }
    else {
        quantidade = 10;
    }

    Artist *resposta = static_cast<Artist *>(malloc(quantidade * sizeof(artist)));

    inputFile.seekg(0,ios::end);
    long total = (inputFile.tellg())/sizeof(Artist);

    for (int i = 0; i < quantidade; i++) {
        int sorteio = rand() % total;
        int posicao = sorteio * sizeof(Artist);
        inputFile.seekg(posicao);
        inputFile.read((char *) &artist, sizeof(Artist));
        resposta[i] = artist;
    }

    inputFile.close();
    return resposta;
}

void gerarArquivoBinArtist(char *caminho) {
    char origem[100];
    char destino[100];

    strcpy(origem, caminho);
    strcpy(destino, caminho);

    strcat(origem, "/artists.csv");
    strcat(destino, "/artists.bin");

    std::string id;
    std::string followers;
    std::string genre;
    std::string name;
    std::string popularity;

    std::string valor;
    std::string texto;

    std::ofstream outputFile(destino, std::ifstream::out | std::ifstream::binary);

    std::ifstream inputFile(origem, std::ifstream::in);
    getline (inputFile,texto);
    getline (inputFile,texto);

    while (inputFile.good()) {

        valor = "";
        int campo = 1;
        bool aspas_abertas = false;

        for (int i = 0; i < texto.size(); i++) {
            if (texto[i] == '"') aspas_abertas = not aspas_abertas;

            if (((texto[i] == ',') && (not aspas_abertas)) || (texto[i] == '\n') || (texto[i] == '\r')) {
                if (campo == 1) id = valor;
                if (campo == 2) followers = valor;
                if (campo == 3) genre = valor;
                if (campo == 4) name = valor;
                if (campo == 5) popularity = valor;
                valor = "";
                campo++;
            } else {
                if (texto[i] != '"') {
                    valor = valor + texto[i];
                }
            }
        }
        char *cstr_id = const_cast<char *>(id.c_str());
        char *cstr_genre = const_cast<char *>(genre.c_str());
        char *cstr_name = const_cast<char *>(name.c_str());
        char *cstr_followers = const_cast<char *>(followers.c_str());
        char *cstr_popularity = const_cast<char *>(popularity.c_str());

//        cout << cstr_id << "|" << cstr_name << "|" << cstr_genre << "|" << cstr_followers << "|" << cstr_popularity << endl;

        Artist *artist = new Artist(cstr_id, cstr_followers, cstr_genre, cstr_name, cstr_popularity);

        artist->binarySave(outputFile);

        getline (inputFile,texto);
    }

    inputFile.close();
    outputFile.close();
}

void imprimirConsoleArtists(Artist* artists) {
    for (int i = 0; i < 10; i++) {
        artists[i].printArtist();
    }
}

void gravarArquivoArtists(char* caminho, Artist* artists) {

    char destino[100];
    strcpy(destino, caminho);
    strcat(destino, "/artists.txt");

    ofstream saida;
    saida.open(destino);
    for (int i = 0; i < 100; i++) {
        artists[i].textSave(saida);
    }
    saida.close();
}

bool verificarArquivoBinArtistExistente(char *caminho) {
    FILE *entrada;
    bool resultado;

    char origem[100];

    strcpy(origem, caminho);
    strcat(origem, "/artists.bin");

    entrada = fopen(origem, "rb");
    if (entrada != NULL) {
        resultado = true;
        fclose(entrada);
    } else {
        resultado = false;
    }
    
    return resultado;
}


Track* lerArquivoBinTrack(char *caminho, int opcao) {
    Track track;

    char origem[100];
    strcpy(origem, caminho);
    strcat(origem, "/tracks.bin");

    std::ifstream inputFile(origem, std::ifstream::in | std::ifstream::binary);

    int quantidade;
    if (opcao == 2) {
        quantidade = 100;
    }
    else {
        quantidade = 10;
    }

    Track *resposta = static_cast<Track *>(malloc(quantidade * sizeof(track)));

    inputFile.seekg(0,ios::end);
    long total = (inputFile.tellg())/sizeof(Track);

    for (int i = 0; i < quantidade; i++) {
        int sorteio = rand() % total;
        int posicao = sorteio * sizeof(Track);
        inputFile.seekg(posicao);
        inputFile.read((char *) &track, sizeof(Track));
        resposta[i] = track;
    }

    inputFile.close();
    return resposta;
}

void gerarArquivoBinTrack(char *caminho) {
    char origem[100];
    char destino[100];

    strcpy(origem, caminho);
    strcpy(destino, caminho);

    strcat(origem, "/tracks.csv");
    strcat(destino, "/tracks.bin");

    std::string id;
    std::string name;
    std::string artist;
    std::string id_artist;
    std::string release_date;
    std::string isExp;
    std::string popularity;
    std::string duration;
    std::string key;
    std::string mode;
    std::string time_signature;
    std::string speechiness;
    std::string acousticness;
    std::string instrumentalness;
    std::string liveness;
    std::string valence;
    std::string tempo;
    std::string loudness;
    std::string danceability;
    std::string energy;


    std::string valor;
    std::string texto;

    std::ofstream outputFile(destino, std::ifstream::out | std::ifstream::binary);

    std::ifstream inputFile(origem, std::ifstream::in);
    getline (inputFile,texto);
    getline (inputFile,texto);

    while (inputFile.good()) {

        valor = "";
        int campo = 1;
        bool aspas_abertas = false;

        for (int i = 0; i < texto.size(); i++) {
            if (texto[i] == '"') aspas_abertas = not aspas_abertas;

            if (((texto[i] == ',') && (not aspas_abertas)) || (texto[i] == '\n') || (texto[i] == '\r')) {
                if (campo == 1) id = valor;
                if (campo == 2) name = valor;
                if (campo == 3) popularity = valor;
                if (campo == 4) duration = valor;
                if (campo == 5) isExp = valor;
                if (campo == 6) artist = valor;
                if (campo == 7) id_artist = valor;
                if (campo == 8) release_date = valor;
                if (campo == 9) danceability = valor;
                if (campo == 10) energy = valor;
                if (campo == 11) key = valor;
                if (campo == 12) loudness = valor;
                if (campo == 13) mode = valor;
                if (campo == 14) speechiness = valor;
                if (campo == 15) acousticness = valor;
                if (campo == 16) instrumentalness = valor;
                if (campo == 17) liveness = valor;
                if (campo == 18) valence = valor;
                if (campo == 19) tempo = valor;
                if (campo == 20) time_signature = valor;
                valor = "";
                campo++;
            } else {
                if (texto[i] != '"') {
                    valor = valor + texto[i];
                }
            }
        }

        char *cstr_id = const_cast<char *>(id.c_str());
        char *cstr_name = const_cast<char *>(name.c_str());
        char *cstr_artist = const_cast<char *>(artist.c_str());
        char *cstr_id_artist = const_cast<char *>(id_artist.c_str());
        char *cstr_release_date = const_cast<char *>(release_date.c_str());
        char *cstr_isExp = const_cast<char *>(isExp.c_str());
        char *cstr_popularity = const_cast<char *>(popularity.c_str());
        char *cstr_duration = const_cast<char *>(duration.c_str());
        char *cstr_key = const_cast<char *>(key.c_str());
        char *cstr_mode = const_cast<char *>(mode.c_str());
        char *cstr_time_signature = const_cast<char *>(time_signature.c_str());
        char *cstr_speechiness = const_cast<char *>(speechiness.c_str());
        char *cstr_acousticness = const_cast<char *>(acousticness.c_str());
        char *cstr_instrumentalness = const_cast<char *>(instrumentalness.c_str());
        char *cstr_liveness = const_cast<char *>(liveness.c_str());
        char *cstr_valence = const_cast<char *>(valence.c_str());
        char *cstr_tempo = const_cast<char *>(tempo.c_str());
        char *cstr_loudness = const_cast<char *>(loudness.c_str());
        char *cstr_danceability = const_cast<char *>(danceability.c_str());
        char *cstr_energy = const_cast<char *>(energy.c_str());

        // cout << cstr_id << "|" << cstr_name << endl;

        Track *track = new Track(cstr_id, cstr_name, cstr_artist, cstr_id_artist, cstr_release_date,
                                 cstr_isExp, cstr_popularity, cstr_duration,
                                 cstr_danceability, cstr_energy, cstr_key,
                                 cstr_loudness, cstr_mode,
                                 cstr_speechiness, cstr_acousticness, cstr_instrumentalness,
                                 cstr_liveness, cstr_valence, cstr_tempo, cstr_time_signature);

        track->binarySave(outputFile);

        getline (inputFile,texto);
    }

    inputFile.close();
    outputFile.close();
}

void imprimirConsoleTracks(Track* tracks) {
    for (int i = 0; i < 10; i++) {
        tracks[i].printTrack();
    }
}

void gravarArquivoTracks(char* caminho, Track* tracks) {

    char destino[100];
    strcpy(destino, caminho);
    strcat(destino, "/tracks.txt");

    ofstream saida;
    saida.open(destino);
    for (int i = 0; i < 100; i++) {
        tracks[i].textSave(saida);
    }
    saida.close();
}

bool verificarArquivoBinTrackExistente(char *caminho) {
    FILE *entrada;
    bool resultado;

    char origem[100];

    strcpy(origem, caminho);
    strcat(origem, "/tracks.bin");

    entrada = fopen(origem, "rb");
    if (entrada != NULL) {
        resultado = true;
        fclose(entrada);
    } else {
        resultado = false;
    }
    return resultado;
}

int main(int argc, char *argv[ ]) {

    argv[1] = "../../input/";
    char* caminho = argv[1];

    int tipo;
    printf("Digite 1=Artist / 2=Track: ");
    scanf("%d", &tipo);

    int saida;
    printf("Digite 1=Console / 2=Arquivo: ");
    scanf("%d", &saida);

    if (tipo == 1) {
        if (!verificarArquivoBinArtistExistente(caminho)) {
            gerarArquivoBinArtist(caminho);
        }
        Artist *artists = lerArquivoBinArtist(caminho, saida);
        if (saida == 1) {
            imprimirConsoleArtists(artists);
        } else {
            if (saida == 2) {
                gravarArquivoArtists(caminho, artists);
            }
        }
    } else {
        if (tipo == 2) {
            if (!verificarArquivoBinTrackExistente(caminho)) {
                gerarArquivoBinTrack(caminho);
            }
            Track *tracks = lerArquivoBinTrack(caminho, saida);
            if (saida == 1) {
                imprimirConsoleTracks(tracks);
            } else {
                if (saida == 2) {
                    gravarArquivoTracks(caminho, tracks);
                }
            }
        }
    }

    return 0;
}
