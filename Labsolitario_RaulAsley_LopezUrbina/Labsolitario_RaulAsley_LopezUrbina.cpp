#include "pch.h"
#include "List.h"
#include"ListaCartas.h"

using namespace System;
public ref class EClass : public Exception {
    //Exception cref
};


int main(array<System::String ^> ^args)
{
    List* myList = new List();
    ListaCartas* Mazo = new ListaCartas();

    int opcion = 0;
    do
    {
        //Se despliega el menú
        Console::WriteLine("Seleccione una opción\n***************************************");
        Console::WriteLine("1) Insertar un dato.");
        Console::WriteLine("2) Ver datos Guardados.");
        Console::WriteLine("3) Insertar nueva carta.");
        Console::WriteLine("4) Sacar una carta alazar.");
        Console::WriteLine("5) Listar Cartas.");
        Console::WriteLine("6) Salir.");

        opcion = int::Parse(Console::ReadLine());
        switch (opcion)
        {
        case 1: {
            try
            {
                Console::WriteLine("Ingrese un dato:");
                myList->Add(Convert::ToInt32(Console::ReadLine()));
                Console::WriteLine("Dato guardado, presione enter para continuar.");
                Console::ReadKey();
                Console::Clear();
                break;
            }
            catch (Exception^ ArgumentException)
            {
                //Console::WriteLine(System.ArgumentOutOfRangeException);
                Console::WriteLine("Caracter inválido.");
            }

        }
        case 2: {
            try
            {
                Console::WriteLine("El listado es:");
                for (int i = 0; i < myList->Count(); i++)
                {
                    Console::WriteLine("[ " + i + " ] = " + myList->GetItem(i));
                }
                Console::WriteLine("Dato mostrados exitosamente, presione enter para continuar.");
                Console::ReadKey();
                Console::Clear();
                break;
            }
            catch (EClass^)
            {
                Console::WriteLine("Caracter inválido.");
            }

        }
        case 3: {
            try
            {
                Console::WriteLine("Ingrese los datos de la carta.");
                Cartas* myCarta = new Cartas();
                Console::WriteLine("Ingrese número de la carta.");
                myCarta->setNumero(Convert::ToInt32(Console::ReadLine()));

                Console::WriteLine("Ingrese el color de la carta: R / N .");
                myCarta->setColor(Convert::ToChar(Console::ReadLine()));

                Console::WriteLine("Ingrese el símbolo de la carta: C / E / T / D");
                myCarta->setSimbolo(Convert::ToChar(Console::ReadLine()));

                Mazo->Add(myCarta);

                Console::WriteLine("********************************\nCarta Guardada de forma correcta. Presione cualquier tecla para continuar.");
                Console::ReadKey();
                Console::Clear();
                break;
            }
            catch (EClass^)
            {
                Console::WriteLine("Caracter inválido.");
            }

        }
        case 4: {
            try
            {
                Console::WriteLine("Se está escogiendo una carta alazar");
                if (Mazo->Count() == 0) {
                    Console::WriteLine("El mazo está vacío. Presione cualquier tecla para continuar.");
                    Console::ReadKey();
                    Console::Clear();
                }
                else {
                    int random = (gcnew Random())->Next(Mazo->Count());
                    Cartas* seleccionada = Mazo->GetItem(random);

                    Console::WriteLine("La Carta es: ");
                    Console::WriteLine("" + seleccionada->getNumero() + " - " + seleccionada->getColor() + " - " + seleccionada->getNumero());
                    Console::WriteLine("Presione cualquier tecla para continuar.");
                    Console::ReadKey();
                    Console::Clear();
                }

            }
            catch (EClass^)
            {
                Console::WriteLine("Caracter inválido.");
            }
            break;
        }
        case 5: {
            Console::WriteLine("Mostrando todas las cartas: ");
            for (int i = 0; i < Mazo->Count(); i++)
            {
                Console::WriteLine("La carta en la posición:" + i + " es:");
                Console::WriteLine("" + Mazo->GetItem(i)->getNumero() + " - " + Mazo->GetItem(i)->getColor() + " - " + Mazo->GetItem(i)->getSimbolo());
            }
            Console::WriteLine("Cartas mostradas con éxito. Presione cualquier tecla para continuar.");
            Console::ReadKey();
            Console::Clear();
            break;
        }

        case 6: {
            Console::WriteLine("Nos vemos pronto.");
            break;
        }
        default: {
            Console::WriteLine("Opción no válida. Presione cualquier tecla para continuar.");
            Console::ReadKey();
            Console::Clear();
            break;
        }

        }
    } while (opcion != 6);
    return 0;
}
