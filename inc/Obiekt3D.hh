#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH
/*!
 * \file
 * \brief Definicja klasy abstrakcyjnej Obiekt3D
 *
 * Plik zawiera definicje klasy abstrakcyjnej Obiekt3D,
 * oraz deklaracje wirtualnych metod tej klasy.
 */
#include"MacOb.hh"
#include"Dr3D_gnuplot_api.hh"
/*!
* \brief Model pojęcia trójwymiarowego obiektu
*
* Klasa abstrakcyjna modeluje ogólne pojęcie 
* trójwymiarowego obiektu
*/
class Obiekt3D{
    protected:
    /*!
    * \brief Środek obiektu trójwymiarowego
    * 
    * Zmienna zawiera współrzędne środka
    * trójwymiarowego obiektu. Wokół tego 
    * punktu następuje obrót obiektu.
    */
    Wektor<double,3> srodek;
    /*!
    * \brief Orientacja obiektu trójwymiarowego
    * 
    * Reprezentuje orientację obiektu
    * względem globalnego układu współrzędnych
    */
    MacOb orient;
    /*!
    * \brief Id obiektu 
    * 
    * Zmienna służąca do przechowywania id
    * obiektu rysowanego w gnuplocie
    */
    int id;
    /*!
    * \brief Wskaźnik do programu graficznego
    * 
    * Zmienna wskaźnikowa do programu graficznego,
    * w którym odbywa się rysowanie obiektu.
    */
    drawNS::Draw3DAPI *gplt;
    public:
    /*!
    * \brief Metoda rysująca trójwymiarowy obiekt
    * 
    * Rysuje obiekt w programie graficznym, do którego
    * wskaźnik posiada obiekt. 
    */
    virtual void Rysuj()=0;
    /*!
    * \brief Metoda obracająca trójwymiarowy obiekt
    * 
    * Zmienia macierz orientacji obiektu o wybrany kat
    * (W osi z). Obrót następuje błyskawicznie(nie jest 
    * animowany) \n
    * \param[in] kat - wartość kąta, o który ma zostać obrócony obiekt 
    */
    virtual void Obroc(double kat)=0;
    /*!
    * \brief Metoda przesuwająca obiekt
    * 
    * Zmienia położenie obiektu w przód
    * o wybraną odległość. Ruch następuje błyskawicznie
    * (nie jest animowany) \n
    * \param[in] odl - odległość o jaką obiekt ma się przesunąć
    */
    virtual void Ruszaj(double odl)=0;
    /*!
    * \brief Metoda ruszająca obiektem w osi z
    * 
    * Zmienia położenie obiektu w osi z
    * o wybraną wartość. Ruch następuje błyskawicznie
    * (nie jest animowany) \n
    * \param[in] odl - odleglosc o jaka ma sie wzniesc/opasc obiekt
    */
    virtual void Wznies_Opusc(double odl)=0;
    /*!
    * \brief Metoda wymazująca obiekt
    * 
    * Wymazuje obiekt z programu graficznego.
    * Jest używana za każdym razem, gdy w 
    * metodzie jest metoda Rysuj()
    */
    virtual void Wymaz()=0;
};
#endif