#include <check.h>
#include "main.c" // Incluye el archivo a testear

START_TEST(test_jugaron_juntos_mismo_club_mismo_tiempo) {
    club_t club1[NMAX] = {
        {"Boca", 2014, 2018},
        {TERM}
    };
    club_t club2[NMAX] = {
        {"Boca", 2016, 2020},
        {TERM}
    };
    futbolista_t jugador1 = {"Juan", {club1[0], club1[1]}};
    futbolista_t jugador2 = {"Pedro", {club2[0], club2[1]}};
    ck_assert_int_eq(futJugaronJuntxs(jugador1, jugador2), 1);
}
END_TEST

START_TEST(test_no_jugaron_juntos_distinto_club) {
    club_t club1[NMAX] = {
        {"Boca", 2014, 2018},
        {TERM}
    };
    club_t club2[NMAX] = {
        {"River", 2016, 2020},
        {TERM}
    };
    futbolista_t jugador1 = {"Juan", {club1[0], club1[1]}};
    futbolista_t jugador2 = {"Pedro", {club2[0], club2[1]}};
    ck_assert_int_eq(futJugaronJuntxs(jugador1, jugador2), 0);
}
END_TEST

START_TEST(test_no_jugaron_juntos_mismo_club_distinto_tiempo) {
    club_t club1[NMAX] = {
        {"Boca", 2010, 2012},
        {TERM}
    };
    club_t club2[NMAX] = {
        {"Boca", 2013, 2015},
        {TERM}
    };
    futbolista_t jugador1 = {"Juan", {club1[0], club1[1]}};
    futbolista_t jugador2 = {"Pedro", {club2[0], club2[1]}};
    ck_assert_int_eq(futJugaronJuntxs(jugador1, jugador2), 0);
}
END_TEST

START_TEST(test_jugaron_juntos_varios_clubes) {
    club_t club1[NMAX] = {
        {"Boca", 2010, 2012},
        {"River", 2013, 2015},
        {"Huracan", 2016, 2018},
        {TERM}
    };
    club_t club2[NMAX] = {
        {"Huracan", 2017, 2019},
        {"Independiente", 2012, 2014},
        {TERM}
    };
    futbolista_t jugador1 = {"Juan", {club1[0], club1[1], club1[2], club1[3]}};
    futbolista_t jugador2 = {"Pedro", {club2[0], club2[1], club2[2]}};
    ck_assert_int_eq(futJugaronJuntxs(jugador1, jugador2), 1);
}
END_TEST

Suite *futbolista_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Futbolista");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_jugaron_juntos_mismo_club_mismo_tiempo);
    tcase_add_test(tc_core, test_no_jugaron_juntos_distinto_club);
    tcase_add_test(tc_core, test_no_jugaron_juntos_mismo_club_distinto_tiempo);
    tcase_add_test(tc_core, test_jugaron_juntos_varios_clubes);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = futbolista_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}