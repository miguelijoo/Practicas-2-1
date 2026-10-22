// persons-test.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good Idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <string>
#include <catalog.h>
#include "gtest/gtest.h"

TEST(CyclistCatalog, Constructor){
  CyclistCatalog c;
  EXPECT_EQ(0, c.Size());
}
TEST(CyclistCatalog, LoadySize){
  CyclistCatalog catalog;
  EXPECT_EQ(0, catalog.Size());

  std::string path = std::string(PROJECT_ROOT) + "/data/cyclists.csv";
  EXPECT_TRUE(catalog.Load(path));
  EXPECT_EQ(100, catalog.Size());
}
TEST(CyclistCatalog, LoadERROR){
  CyclistCatalog catalog;
  EXPECT_FALSE(catalog.Load("../data/cycxxxxx.csv"));
}
TEST(CyclistCatalog, Data){
  CyclistCatalog catalog;
  std::string path = std::string(PROJECT_ROOT) + "/data/cyclists.csv";
  EXPECT_TRUE(catalog.Load(path));
  EXPECT_EQ("Joao Almeida",catalog.Data()[2].GetName());
  EXPECT_EQ("Emanuel Buchmann",catalog.Data()[99].GetName());
  EXPECT_EQ(1992,catalog.Data()[99].GetBirthYear());
}

TEST(CyclistCatalog, GetTeam){
  CyclistCatalog catalog;
  std::string path = std::string(PROJECT_ROOT) + "/data/cyclists.csv";
  EXPECT_TRUE(catalog.Load(path));
  EXPECT_EQ("visma lease a bike",catalog.GetTeam("c0a1b106"));
  EXPECT_EQ("ineos grenadiers",catalog.GetTeam("c0a1b202"));
  EXPECT_EQ("NOT_IN_CATALOG",catalog.GetTeam("99999"));
}

TEST(CyclistCatalog, GetByTeam){
  CyclistCatalog catalog;
  std::string path = std::string(PROJECT_ROOT) + "/data/cyclists.csv";
  EXPECT_TRUE(catalog.Load(path));
  std::vector<Cyclist> v= catalog.GetByTeam("visma lease a bike");
  EXPECT_EQ(10, v.size());
  EXPECT_EQ("Jonas Vingegaard", v[0].GetName());
  EXPECT_EQ("Wout van Aert", v[1].GetName());
  EXPECT_EQ("Sepp Kuss", v[2].GetName());
  EXPECT_EQ("Christophe Laporte", v[3].GetName());
  EXPECT_EQ("Dylan van Baarle", v[4].GetName());
  EXPECT_EQ("Matteo Jorgenson", v[5].GetName());
  EXPECT_EQ("Tiesj Benoot", v[6].GetName());
  EXPECT_EQ("Jan Tratnik", v[7].GetName());
  EXPECT_EQ("Olav Kooij", v[8].GetName());
  EXPECT_EQ("Attila Valter", v[9].GetName());
  v= catalog.GetByTeam("uae team emirates");
  EXPECT_EQ("Tadej Pogacar", v[0].GetName());
  EXPECT_EQ("Adam Yates", v[1].GetName());
  EXPECT_EQ("Joao Almeida", v[2].GetName());
  EXPECT_EQ("Juan Ayuso", v[3].GetName());
  EXPECT_EQ("Brandon McNulty", v[4].GetName());
  EXPECT_EQ("Rafal Majka", v[5].GetName());
  EXPECT_EQ("Marc Soler", v[6].GetName());
  EXPECT_EQ("Tim Wellens", v[7].GetName());
  EXPECT_EQ("Felix Grossschartner", v[8].GetName());
  EXPECT_EQ("Pavel Sivakov", v[9].GetName());
}

TEST(CyclistCatalog, GetYoungest){
  CyclistCatalog catalog;
  std::string path = std::string(PROJECT_ROOT) + "/data/cyclists.csv";
  EXPECT_TRUE(catalog.Load(path));
  std::vector<Cyclist> v= catalog.GetYoungest();
  EXPECT_EQ("Juan Ayuso", v[0].GetName());
}

TEST(CyclistCatalog, Clear){
  CyclistCatalog catalog;
  std::string path = std::string(PROJECT_ROOT) + "/data/directors.csv";
  EXPECT_EQ(0,catalog.Size());
  catalog.Clear();
  EXPECT_EQ(0,catalog.Size());
  EXPECT_TRUE(catalog.Load(path));
  catalog.Clear();
  EXPECT_EQ(0,catalog.Size());
}


TEST(CyclistCatalog, AddFirst) {
    CyclistCatalog catalog;

    Cyclist c1;
    c1.SetCyclistId("C1");

    Cyclist c2;
    c2.SetCyclistId("C2");

    catalog.AddFirst(c1);

    ASSERT_EQ(catalog.Size(), 1);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C1");

    catalog.AddFirst(c2);

    ASSERT_EQ(catalog.Size(), 2);
    EXPECT_EQ(catalog.Data()[0].GetCyclistId(), "C2");
    EXPECT_EQ(catalog.Data()[1].GetCyclistId(), "C1");
}

TEST(CyclistCatalogTest, AddLast) {
    CyclistCatalog catalog;

    Cyclist c1, c2;
    c1.SetCyclistId("C1");
    c2.SetCyclistId("C2");

    catalog.AddLast(c1);

    ASSERT_EQ(catalog.Size(), 1);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C1");

    catalog.AddLast(c2);

    ASSERT_EQ(catalog.Size(), 2);
    EXPECT_EQ(catalog.Data()[0].GetCyclistId(), "C1");
    EXPECT_EQ(catalog.Data()[1].GetCyclistId(), "C2");
}

TEST(CyclistCatalogTest, RemoveFirst) {
    CyclistCatalog catalog;

    EXPECT_FALSE(catalog.RemoveFirst());
    EXPECT_EQ(catalog.Size(), 0);

    Cyclist c1, c2;
    c1.SetCyclistId("C1");
    c2.SetCyclistId("C2");

    catalog.AddFirst(c1);
    catalog.AddFirst(c2); // C2, C1

    EXPECT_TRUE(catalog.RemoveFirst());
    ASSERT_EQ(catalog.Size(), 1);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C1");

    // Elimina ciclista restante.
    EXPECT_TRUE(catalog.RemoveFirst());
    EXPECT_EQ(catalog.Size(), 0);

    // El catálogo vuelve a estar vacío.
    EXPECT_FALSE(catalog.RemoveFirst());
    EXPECT_EQ(catalog.Size(), 0);
}

TEST(CyclistCatalog, RemoveLast) {
    CyclistCatalog catalog;

    EXPECT_FALSE(catalog.RemoveLast());
    EXPECT_EQ(catalog.Size(), 0);

    Cyclist c1;
    c1.SetCyclistId("C1");

    Cyclist c2;
    c2.SetCyclistId("C2");

    catalog.AddFirst(c1);
    catalog.AddFirst(c2); // Orden: C2, C1

    EXPECT_TRUE(catalog.RemoveLast());

    ASSERT_EQ(catalog.Size(), 1);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C2");

    EXPECT_TRUE(catalog.RemoveLast());
    EXPECT_EQ(catalog.Size(), 0);

    EXPECT_FALSE(catalog.RemoveLast());
    EXPECT_EQ(catalog.Size(), 0);
}

TEST(CyclistCatalog, Remove) {
    CyclistCatalog catalog;

    EXPECT_FALSE(catalog.Remove("C1"));

    Cyclist c1, c2, c3;
    c1.SetCyclistId("C1");
    c2.SetCyclistId("C2");
    c3.SetCyclistId("C3");

    catalog.AddFirst(c3);
    catalog.AddFirst(c2);
    catalog.AddFirst(c1); // Orden: C1, C2, C3

    EXPECT_FALSE(catalog.Remove("C4"));
    ASSERT_EQ(catalog.Size(), 3u);

    // Borra el elemento intermedio.
    EXPECT_TRUE(catalog.Remove("C2"));
    ASSERT_EQ(catalog.Size(), 2u);
    EXPECT_EQ(catalog.Data()[0].GetCyclistId(), "C1");
    EXPECT_EQ(catalog.Data()[1].GetCyclistId(), "C3");

    // Borra el primer elemento.
    EXPECT_TRUE(catalog.Remove("C1"));
    ASSERT_EQ(catalog.Size(), 1u);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C3");

    // Borra el único elemento restante.
    EXPECT_TRUE(catalog.Remove("C3"));
    EXPECT_EQ(catalog.Size(), 0u);

    EXPECT_FALSE(catalog.Remove("C3"));
}

TEST(CyclistCatalog, RemoveAt) {
    CyclistCatalog catalog;

    EXPECT_FALSE(catalog.RemoveAt(0));

    Cyclist c1, c2, c3;
    c1.SetCyclistId("C1");
    c2.SetCyclistId("C2");
    c3.SetCyclistId("C3");

    catalog.AddFirst(c3);
    catalog.AddFirst(c2);
    catalog.AddFirst(c1); // Orden: C1, C2, C3

    // Posición inválida: no debe modificar el catálogo.
    EXPECT_FALSE(catalog.RemoveAt(-1));
    EXPECT_FALSE(catalog.RemoveAt(-5));
    ASSERT_EQ(catalog.Size(), 3);    

    // Posición inválida: no debe modificar el catálogo.
    EXPECT_FALSE(catalog.RemoveAt(3));
    ASSERT_EQ(catalog.Size(), 3);
    EXPECT_EQ(catalog.Data()[0].GetCyclistId(), "C1");
    EXPECT_EQ(catalog.Data()[1].GetCyclistId(), "C2");
    EXPECT_EQ(catalog.Data()[2].GetCyclistId(), "C3");

    // Borra el elemento intermedio.
    EXPECT_TRUE(catalog.RemoveAt(1));
    ASSERT_EQ(catalog.Size(), 2);
    EXPECT_EQ(catalog.Data()[0].GetCyclistId(), "C1");
    EXPECT_EQ(catalog.Data()[1].GetCyclistId(), "C3");

    // Borra el último elemento.
    EXPECT_TRUE(catalog.RemoveAt(1));
    ASSERT_EQ(catalog.Size(), 1);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C1");

    // Borra el único elemento restante.
    EXPECT_TRUE(catalog.RemoveAt(0));
    EXPECT_EQ(catalog.Size(), 0);

    EXPECT_FALSE(catalog.RemoveAt(0));
}


TEST(CyclistCatalog, RemoveByTeam) {
    CyclistCatalog catalog;

    EXPECT_EQ(catalog.RemoveByTeam("Equipo A"), 0u);

    Cyclist c1, c2, c3, c4;
    c1.SetCyclistId("C1");
    c1.SetTeam("Equipo A");

    c2.SetCyclistId("C2");
    c2.SetTeam("Equipo A");

    c3.SetCyclistId("C3");
    c3.SetTeam("Equipo B");

    c4.SetCyclistId("C4");
    c4.SetTeam("Equipo A");

    catalog.AddFirst(c4);
    catalog.AddFirst(c3);
    catalog.AddFirst(c2);
    catalog.AddFirst(c1); // Orden: C1, C2, C3, C4

    // Equipo inexistente: no elimina nada.
    EXPECT_EQ(catalog.RemoveByTeam("Equipo C"), 0);
    ASSERT_EQ(catalog.Size(), 4);

    // Elimina tres ciclistas, incluidos dos consecutivos.
    EXPECT_EQ(catalog.RemoveByTeam("Equipo A"), 3);
    ASSERT_EQ(catalog.Size(), 1);
    EXPECT_EQ(catalog.Data().front().GetCyclistId(), "C3");

    // El equipo eliminado ya no tiene ciclistas.
    EXPECT_EQ(catalog.RemoveByTeam("Equipo A"), 0);
    EXPECT_EQ(catalog.Size(), 1);

    // Elimina el último ciclista.
    EXPECT_EQ(catalog.RemoveByTeam("Equipo B"), 1);
    EXPECT_EQ(catalog.Size(), 0);
}


TEST(CyclistCatalog, RemoveRange) {
    CyclistCatalog catalog;

    // Catálogo vacío.
    EXPECT_TRUE(catalog.RemoveRange(0, 0));
    EXPECT_FALSE(catalog.RemoveRange(0, 1));

    Cyclist c1, c2, c3, c4;
    c1.SetCyclistId("C1");
    c2.SetCyclistId("C2");
    c3.SetCyclistId("C3");
    c4.SetCyclistId("C4");

    catalog.AddFirst(c4);
    catalog.AddFirst(c3);
    catalog.AddFirst(c2);
    catalog.AddFirst(c1); // Orden: C1, C2, C3, C4

    // Intervalos inválidos.
    EXPECT_FALSE(catalog.RemoveRange(3, 2));
    EXPECT_FALSE(catalog.RemoveRange(0, 5));
    EXPECT_FALSE(catalog.RemoveRange(5, 5));
    ASSERT_EQ(catalog.Size(), 4);

    // Intervalos vacíos válidos.
    EXPECT_TRUE(catalog.RemoveRange(2, 2));
    EXPECT_TRUE(catalog.RemoveRange(4, 4));
    ASSERT_EQ(catalog.Size(), 4);

    // [1, 3) elimina C2 y C3; conserva C1 y C4.
    EXPECT_TRUE(catalog.RemoveRange(1, 3));
    ASSERT_EQ(catalog.Size(), 2);
    EXPECT_EQ(catalog.Data()[0].GetCyclistId(), "C1");
    EXPECT_EQ(catalog.Data()[1].GetCyclistId(), "C4");

    // Elimina todos los elementos.
    EXPECT_TRUE(catalog.RemoveRange(0, catalog.Size()));
    EXPECT_EQ(catalog.Size(), 0);
}


TEST(DirectorCatalog, Constructor){
  DirectorCatalog c;
  EXPECT_EQ(0, c.Size());
}
TEST(DirectorCatalog, Load){
  DirectorCatalog catalog;
  EXPECT_EQ(0, catalog.Size());

  std::string path = std::string(PROJECT_ROOT) + "/data/directors.csv";
  EXPECT_TRUE(catalog.Load(path));
  EXPECT_EQ(10, catalog.Size());
}
TEST(DirectorCatalog, LoadERROR){
  DirectorCatalog catalog;
  EXPECT_FALSE(catalog.Load("../data/cycxxxxx.csv"));
}
TEST(DirectorCatalog, Data){
  DirectorCatalog catalog;
  std::string path = std::string(PROJECT_ROOT) + "/data/directors.csv";
  EXPECT_TRUE(catalog.Load(path));
  EXPECT_EQ("Rod Ellingworth",catalog.Data()[2].GetName());
  EXPECT_EQ("Enrico Poitschke",catalog.Data()[9].GetName());
  EXPECT_EQ(1969,catalog.Data()[9].GetBirthYear());
  EXPECT_EQ(2017,catalog.Data()[9].GetDirectorSince());
}