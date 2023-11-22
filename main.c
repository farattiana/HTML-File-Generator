#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LENGTH 1000

bool changeWorkingDirectory();

bool createAssetsFolder();

bool createSrcFolder();

bool createSubFolder();

bool createHTMLFile();

bool createCSSFile();

bool createJsFile();

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        printf("Veuillez utiliser la commande :create-html-repository\n");
        return 1;
    }

    if (!changeWorkingDirectory())
        return 1;

    if (!createSrcFolder())
        return 1;

    if (!createAssetsFolder())
        return 1;

    if (!createSubFolder())
        return 1;

    if (!createHTMLFile())
        return 1;

    if (!createCSSFile())
        return 1;

    if (!createJsFile())
        return 1;
    printf("Le répértoire a été créé avec succès.\n");

    return 0;
}

bool changeWorkingDirectory()
{
    char destinationFolder[MAX_LENGTH];
    if (getcwd(destinationFolder, sizeof(destinationFolder)) == NULL)
    {
        perror("Erreur lors de la récupération du répertoire de travail");
        return false;
    }

    if (chdir(destinationFolder) != 0)
    {
        perror("Répertoire de destination invalide ou inaccessible");
        return false;
    }
    else
        return true;
}


bool createAssetsFolder()
{
    if (mkdir("assets", 0777) != 0)
    {
        perror("Erreur lors de la creation du dossier Assets");
        return false;
    }
    else
        return true;
}

bool createSrcFolder()
{
    if (mkdir("src", 0777) != 0)
    {
        perror("Erreur lors de la création du dossier src");
        return false;
    }
    else
        return true;
}

bool createSubFolder()
{
    if (mkdir("assets/images", 0777) != 0)
    {
        perror("Erreur lors de la creation du dossier Assets/image");
        return 1;
    }

    if (mkdir("assets/fonts", 0777) != 0)
    {
        perror("Erreur lors de la creation du dossier Assets/fonts");
        return 1;
    }

    if (mkdir("src/style", 0777) != 0)
    {
        perror("Erreur lors de la création du dossier src/style");
        return false;
    }

    if (mkdir("src/js", 0777) != 0)
    {
        perror("Erreur lors de la création du dossier src/js");
        return false;
    }
    else
        return true;
}


bool createHTMLFile()
{
    FILE* HtmlFile = fopen("index.html", "w");

    if (!HtmlFile)
    {
        perror("Erreur lors de la creation du fichier html");
        return false;
    }
    else
    {
        fprintf(HtmlFile, "<!DOCTYPE html>\n");
        fprintf(HtmlFile, "<html lang=\"en\">\n");
        fprintf(HtmlFile, "<head>\n");
        fprintf(HtmlFile, "\t<meta charset=\"UTF-8\">\n");
        fprintf(HtmlFile, "\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> \n");
        fprintf(HtmlFile, "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n");
        fprintf(HtmlFile, "\t<link rel=\"stylesheet\" href=\"./src/style/index.css\">\n");
        fprintf(HtmlFile, "\t<title> Document</title>\n");
        fprintf(HtmlFile, "</head>\n");
        fprintf(HtmlFile, "<body>\n");
        fprintf(HtmlFile, "\t<script src=\"src/js/index.js\"></script>\n");
        fprintf(HtmlFile, "</body>\n");

        fprintf(HtmlFile, "</html>");

        fclose(HtmlFile);
        return true;
    }
}

bool createCSSFile()
{
    FILE* cssFile = fopen("src/style/index.css", "w");
    if (!cssFile)
    {
        perror("Erreur lors de la création du fichier style.css");
        return false;
    }
    else
    {
        fprintf(cssFile, "*{\n");
        fprintf(cssFile, "\tmargin: 0;\n");
        fprintf(cssFile, "\tpadding: 0;\n");
        fprintf(cssFile, "\tbox-sizing: border-box;\n");
        fprintf(cssFile, "} \n");

        fprintf(cssFile, "\nhtml,body{\n");
        fprintf(cssFile, "\tposition:relative;\n");
        fprintf(cssFile, "\twidth:100vw;\n");
        fprintf(cssFile, "\theight:100vh;\n");
        fprintf(cssFile, "}\n");

        fclose(cssFile);
        return true;
    }
}

bool createJsFile()
{
    FILE* JSFile = fopen("src/js/index.js", "w");
    if (!JSFile)
    {
        perror("Erreur lors de la création du fichier script.js");
        return false;
    }
    fclose(JSFile);

    return true;
}