--
-- PostgreSQL database dump
--

-- Dumped from database version 11.6
-- Dumped by pg_dump version 12rc1

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

--
-- Name: Admin; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Admin" (
    "YoneticiID" integer NOT NULL,
    "Nickname" character varying(100) NOT NULL
);


ALTER TABLE public."Admin" OWNER TO postgres;

--
-- Name: Admın_YonetıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Admın_YonetıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Admın_YonetıcıID_seq" OWNER TO postgres;

--
-- Name: Admın_YonetıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Admın_YonetıcıID_seq" OWNED BY public."Admin"."YoneticiID";


--
-- Name: Cevaplar; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Cevaplar" (
    "CevapID" integer NOT NULL,
    "KullaniciAdi" character varying(100) NOT NULL,
    "OySayisi" integer NOT NULL,
    "Yorum" text,
    "KullaniciD" integer NOT NULL,
    "SoruID" integer NOT NULL,
    "CevapKontrol" integer NOT NULL
);


ALTER TABLE public."Cevaplar" OWNER TO postgres;

--
-- Name: Cevaplar_CevaoID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Cevaplar_CevaoID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Cevaplar_CevaoID_seq" OWNER TO postgres;

--
-- Name: Cevaplar_CevaoID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Cevaplar_CevaoID_seq" OWNED BY public."Cevaplar"."CevapID";


--
-- Name: Cevaplar_CevapKontrol_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Cevaplar_CevapKontrol_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Cevaplar_CevapKontrol_seq" OWNER TO postgres;

--
-- Name: Cevaplar_CevapKontrol_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Cevaplar_CevapKontrol_seq" OWNED BY public."Cevaplar"."CevapKontrol";


--
-- Name: Cevaplar_KullanıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Cevaplar_KullanıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Cevaplar_KullanıcıID_seq" OWNER TO postgres;

--
-- Name: Cevaplar_KullanıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Cevaplar_KullanıcıID_seq" OWNED BY public."Cevaplar"."KullaniciD";


--
-- Name: Cevaplar_SoruID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Cevaplar_SoruID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Cevaplar_SoruID_seq" OWNER TO postgres;

--
-- Name: Cevaplar_SoruID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Cevaplar_SoruID_seq" OWNED BY public."Cevaplar"."SoruID";


--
-- Name: Editor; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Editor" (
    "YoneticiID" integer NOT NULL
);


ALTER TABLE public."Editor" OWNER TO postgres;

--
-- Name: Edıtor_YonetıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Edıtor_YonetıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Edıtor_YonetıcıID_seq" OWNER TO postgres;

--
-- Name: Edıtor_YonetıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Edıtor_YonetıcıID_seq" OWNED BY public."Editor"."YoneticiID";


--
-- Name: EtiketTipi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."EtiketTipi" (
    "EtiketID" integer NOT NULL,
    "EtiketTipID" integer NOT NULL
);


ALTER TABLE public."EtiketTipi" OWNER TO postgres;

--
-- Name: Etiketler; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Etiketler" (
    "EtiketID" integer NOT NULL,
    "Adi" character varying(2044) NOT NULL,
    "SoruID" integer NOT NULL,
    "EtiketDuzeni" integer NOT NULL
);


ALTER TABLE public."Etiketler" OWNER TO postgres;

--
-- Name: Etiketler_Ad_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Etiketler_Ad_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Etiketler_Ad_seq" OWNER TO postgres;

--
-- Name: Etiketler_Ad_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Etiketler_Ad_seq" OWNED BY public."Etiketler"."Adi";


--
-- Name: Etiketler_EtıketID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Etiketler_EtıketID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Etiketler_EtıketID_seq" OWNER TO postgres;

--
-- Name: Etiketler_EtıketID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Etiketler_EtıketID_seq" OWNED BY public."Etiketler"."EtiketID";


--
-- Name: Etiketler_SoruID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Etiketler_SoruID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Etiketler_SoruID_seq" OWNER TO postgres;

--
-- Name: Etiketler_SoruID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Etiketler_SoruID_seq" OWNED BY public."Etiketler"."SoruID";


--
-- Name: EtıketTıpı_EtıketID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."EtıketTıpı_EtıketID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."EtıketTıpı_EtıketID_seq" OWNER TO postgres;

--
-- Name: EtıketTıpı_EtıketID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."EtıketTıpı_EtıketID_seq" OWNED BY public."EtiketTipi"."EtiketID";


--
-- Name: EtıketTıpı_EtıketTıpID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."EtıketTıpı_EtıketTıpID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."EtıketTıpı_EtıketTıpID_seq" OWNER TO postgres;

--
-- Name: EtıketTıpı_EtıketTıpID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."EtıketTıpı_EtıketTıpID_seq" OWNED BY public."EtiketTipi"."EtiketTipID";


--
-- Name: Etıketler_EtıketDuzenı_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Etıketler_EtıketDuzenı_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Etıketler_EtıketDuzenı_seq" OWNER TO postgres;

--
-- Name: Etıketler_EtıketDuzenı_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Etıketler_EtıketDuzenı_seq" OWNED BY public."Etiketler"."EtiketDuzeni";


--
-- Name: Goruntulenme; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Goruntulenme" (
    "ID" integer NOT NULL,
    "GoruntuleyenKullaniciAdi" character varying(100) NOT NULL,
    "GoruntulenmeSayisi" integer NOT NULL,
    "SoruID" integer NOT NULL,
    "CevapID" integer NOT NULL,
    "YorumID" integer NOT NULL
);


ALTER TABLE public."Goruntulenme" OWNER TO postgres;

--
-- Name: Goruntulenme_CevapID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Goruntulenme_CevapID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Goruntulenme_CevapID_seq" OWNER TO postgres;

--
-- Name: Goruntulenme_CevapID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Goruntulenme_CevapID_seq" OWNED BY public."Goruntulenme"."CevapID";


--
-- Name: Goruntulenme_ID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Goruntulenme_ID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Goruntulenme_ID_seq" OWNER TO postgres;

--
-- Name: Goruntulenme_ID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Goruntulenme_ID_seq" OWNED BY public."Goruntulenme"."ID";


--
-- Name: Goruntulenme_SoruID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Goruntulenme_SoruID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Goruntulenme_SoruID_seq" OWNER TO postgres;

--
-- Name: Goruntulenme_SoruID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Goruntulenme_SoruID_seq" OWNED BY public."Goruntulenme"."SoruID";


--
-- Name: Goruntulenme_YorumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Goruntulenme_YorumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Goruntulenme_YorumID_seq" OWNER TO postgres;

--
-- Name: Goruntulenme_YorumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Goruntulenme_YorumID_seq" OWNED BY public."Goruntulenme"."YorumID";


--
-- Name: KullaniciRozet; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KullaniciRozet" (
    "KullaniciID" integer NOT NULL,
    "RozetID" integer NOT NULL
);


ALTER TABLE public."KullaniciRozet" OWNER TO postgres;

--
-- Name: KulanıcıRozet_KullanıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KulanıcıRozet_KullanıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KulanıcıRozet_KullanıcıID_seq" OWNER TO postgres;

--
-- Name: KulanıcıRozet_KullanıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KulanıcıRozet_KullanıcıID_seq" OWNED BY public."KullaniciRozet"."KullaniciID";


--
-- Name: KulanıcıRozet_RozetID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KulanıcıRozet_RozetID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KulanıcıRozet_RozetID_seq" OWNER TO postgres;

--
-- Name: KulanıcıRozet_RozetID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KulanıcıRozet_RozetID_seq" OWNED BY public."KullaniciRozet"."RozetID";


--
-- Name: KullaniciEtiket; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."KullaniciEtiket" (
    "EtiketID" integer NOT NULL,
    "KullaniciID" integer NOT NULL,
    "DuzenlemeYoneticisi" integer NOT NULL
);


ALTER TABLE public."KullaniciEtiket" OWNER TO postgres;

--
-- Name: Kullanicilar; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Kullanicilar" (
    "KullaniciID" integer NOT NULL,
    "Adi" character varying(40) NOT NULL,
    "Soyadi" character varying(40) NOT NULL,
    "Unvan" character varying(40) NOT NULL,
    "E-mail" character varying(40) NOT NULL,
    "YasadigiYer" character varying(2044) NOT NULL,
    "KisiselBilgi" text,
    "Rozetleri" text NOT NULL,
    "ItibarPuani" numeric NOT NULL,
    "Topluluklar" character varying(40),
    "HesapOlusumTarihi" date NOT NULL,
    "SonGirisTarihi" date NOT NULL,
    "Yasi" integer
);


ALTER TABLE public."Kullanicilar" OWNER TO postgres;

--
-- Name: KullanıcıEtıket_DuzenlemeYonetıcısı_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KullanıcıEtıket_DuzenlemeYonetıcısı_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KullanıcıEtıket_DuzenlemeYonetıcısı_seq" OWNER TO postgres;

--
-- Name: KullanıcıEtıket_DuzenlemeYonetıcısı_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KullanıcıEtıket_DuzenlemeYonetıcısı_seq" OWNED BY public."KullaniciEtiket"."DuzenlemeYoneticisi";


--
-- Name: KullanıcıEtıket_EtıketID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KullanıcıEtıket_EtıketID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KullanıcıEtıket_EtıketID_seq" OWNER TO postgres;

--
-- Name: KullanıcıEtıket_EtıketID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KullanıcıEtıket_EtıketID_seq" OWNED BY public."KullaniciEtiket"."EtiketID";


--
-- Name: KullanıcıEtıket_KullanıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."KullanıcıEtıket_KullanıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."KullanıcıEtıket_KullanıcıID_seq" OWNER TO postgres;

--
-- Name: KullanıcıEtıket_KullanıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."KullanıcıEtıket_KullanıcıID_seq" OWNED BY public."KullaniciEtiket"."KullaniciID";


--
-- Name: Kullanıcılar_KullanıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Kullanıcılar_KullanıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Kullanıcılar_KullanıcıID_seq" OWNER TO postgres;

--
-- Name: Kullanıcılar_KullanıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Kullanıcılar_KullanıcıID_seq" OWNED BY public."Kullanicilar"."KullaniciID";


--
-- Name: Moderator; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Moderator" (
    "YoneticiID" integer NOT NULL
);


ALTER TABLE public."Moderator" OWNER TO postgres;

--
-- Name: Moderator_YonetıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Moderator_YonetıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Moderator_YonetıcıID_seq" OWNER TO postgres;

--
-- Name: Moderator_YonetıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Moderator_YonetıcıID_seq" OWNED BY public."Moderator"."YoneticiID";


--
-- Name: OyTipi; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."OyTipi" (
    "ID" integer NOT NULL,
    "Ad" character varying(2044) NOT NULL,
    "OyID" integer NOT NULL,
    "FeedBackID" integer NOT NULL
);


ALTER TABLE public."OyTipi" OWNER TO postgres;

--
-- Name: OyTıpı_Ad_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyTıpı_Ad_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyTıpı_Ad_seq" OWNER TO postgres;

--
-- Name: OyTıpı_Ad_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyTıpı_Ad_seq" OWNED BY public."OyTipi"."Ad";


--
-- Name: OyTıpı_FeedBakID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyTıpı_FeedBakID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyTıpı_FeedBakID_seq" OWNER TO postgres;

--
-- Name: OyTıpı_FeedBakID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyTıpı_FeedBakID_seq" OWNED BY public."OyTipi"."FeedBackID";


--
-- Name: OyTıpı_ID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyTıpı_ID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyTıpı_ID_seq" OWNER TO postgres;

--
-- Name: OyTıpı_ID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyTıpı_ID_seq" OWNED BY public."OyTipi"."ID";


--
-- Name: OyTıpı_OyID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."OyTıpı_OyID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."OyTıpı_OyID_seq" OWNER TO postgres;

--
-- Name: OyTıpı_OyID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."OyTıpı_OyID_seq" OWNED BY public."OyTipi"."OyID";


--
-- Name: Oylar; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Oylar" (
    "OyID" integer NOT NULL,
    "Tarıh" date NOT NULL,
    "KullaniciID" integer NOT NULL,
    "SoruID" integer NOT NULL,
    "CevapID" integer NOT NULL
);


ALTER TABLE public."Oylar" OWNER TO postgres;

--
-- Name: Oylar_CevapID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Oylar_CevapID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Oylar_CevapID_seq" OWNER TO postgres;

--
-- Name: Oylar_CevapID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Oylar_CevapID_seq" OWNED BY public."Oylar"."CevapID";


--
-- Name: Oylar_KullanıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Oylar_KullanıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Oylar_KullanıcıID_seq" OWNER TO postgres;

--
-- Name: Oylar_KullanıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Oylar_KullanıcıID_seq" OWNED BY public."Oylar"."KullaniciID";


--
-- Name: Oylar_OyID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Oylar_OyID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Oylar_OyID_seq" OWNER TO postgres;

--
-- Name: Oylar_OyID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Oylar_OyID_seq" OWNED BY public."Oylar"."OyID";


--
-- Name: Oylar_SoruID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Oylar_SoruID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Oylar_SoruID_seq" OWNER TO postgres;

--
-- Name: Oylar_SoruID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Oylar_SoruID_seq" OWNED BY public."Oylar"."SoruID";


--
-- Name: Rozetler; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Rozetler" (
    "RozetID" integer NOT NULL,
    "RozetAdı" character varying(40) NOT NULL,
    "AlinmaTarihi" date,
    "Sinifi" character varying(40) NOT NULL
);


ALTER TABLE public."Rozetler" OWNER TO postgres;

--
-- Name: Rozetler_RozetID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Rozetler_RozetID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Rozetler_RozetID_seq" OWNER TO postgres;

--
-- Name: Rozetler_RozetID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Rozetler_RozetID_seq" OWNED BY public."Rozetler"."RozetID";


--
-- Name: SoruFeedback; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."SoruFeedback" (
    "FeedBackID" integer NOT NULL,
    "OlusturulmaTarihi" date NOT NULL,
    "SoruID" integer NOT NULL
);


ALTER TABLE public."SoruFeedback" OWNER TO postgres;

--
-- Name: SoruFeedback_FeedBackID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."SoruFeedback_FeedBackID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."SoruFeedback_FeedBackID_seq" OWNER TO postgres;

--
-- Name: SoruFeedback_FeedBackID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."SoruFeedback_FeedBackID_seq" OWNED BY public."SoruFeedback"."FeedBackID";


--
-- Name: SoruFeedback_SoruID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."SoruFeedback_SoruID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."SoruFeedback_SoruID_seq" OWNER TO postgres;

--
-- Name: SoruFeedback_SoruID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."SoruFeedback_SoruID_seq" OWNED BY public."SoruFeedback"."SoruID";


--
-- Name: Sorular; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Sorular" (
    "SoruID" integer NOT NULL,
    "Basligi" character varying(200) NOT NULL,
    "Etiketi" character varying(100) NOT NULL,
    "Tarih" date NOT NULL,
    "GoruntulenmeSayisi" integer NOT NULL,
    "YorumSayisi" integer NOT NULL,
    "KullaniciID" integer NOT NULL,
    "SoruDuzeni" integer NOT NULL
);


ALTER TABLE public."Sorular" OWNER TO postgres;

--
-- Name: Sorular_KullanıcıID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Sorular_KullanıcıID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Sorular_KullanıcıID_seq" OWNER TO postgres;

--
-- Name: Sorular_KullanıcıID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Sorular_KullanıcıID_seq" OWNED BY public."Sorular"."KullaniciID";


--
-- Name: Sorular_SoruDuzenı_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Sorular_SoruDuzenı_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Sorular_SoruDuzenı_seq" OWNER TO postgres;

--
-- Name: Sorular_SoruDuzenı_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Sorular_SoruDuzenı_seq" OWNED BY public."Sorular"."SoruDuzeni";


--
-- Name: Sorular_SoruID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Sorular_SoruID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Sorular_SoruID_seq" OWNER TO postgres;

--
-- Name: Sorular_SoruID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Sorular_SoruID_seq" OWNED BY public."Sorular"."SoruID";


--
-- Name: Yoneticiler; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Yoneticiler" (
    "YoneticiID" integer NOT NULL,
    "Adi" character varying(40) NOT NULL,
    "Soyadi" character varying(40) NOT NULL,
    "Yasi" integer NOT NULL,
    "e-mail" character varying(40) NOT NULL,
    "YasadigiYer" character varying(2044) NOT NULL,
    "KisiselBilgi" text
);


ALTER TABLE public."Yoneticiler" OWNER TO postgres;

--
-- Name: Yorumlar; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public."Yorumlar" (
    "YorumID" integer NOT NULL,
    "OlusturulmaTarihi" date NOT NULL,
    "Text" text NOT NULL,
    "KullaniciAdi" text NOT NULL,
    "CevapID" integer NOT NULL
);


ALTER TABLE public."Yorumlar" OWNER TO postgres;

--
-- Name: Yorumlar_CevapID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Yorumlar_CevapID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Yorumlar_CevapID_seq" OWNER TO postgres;

--
-- Name: Yorumlar_CevapID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Yorumlar_CevapID_seq" OWNED BY public."Yorumlar"."CevapID";


--
-- Name: Yorumlar_YorumID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Yorumlar_YorumID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Yorumlar_YorumID_seq" OWNER TO postgres;

--
-- Name: Yorumlar_YorumID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Yorumlar_YorumID_seq" OWNED BY public."Yorumlar"."YorumID";


--
-- Name: Yöneticiler_YöneticiID_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public."Yöneticiler_YöneticiID_seq"
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public."Yöneticiler_YöneticiID_seq" OWNER TO postgres;

--
-- Name: Yöneticiler_YöneticiID_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public."Yöneticiler_YöneticiID_seq" OWNED BY public."Yoneticiler"."YoneticiID";


--
-- Name: Admin YoneticiID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin" ALTER COLUMN "YoneticiID" SET DEFAULT nextval('public."Admın_YonetıcıID_seq"'::regclass);


--
-- Name: Cevaplar CevapID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevaplar" ALTER COLUMN "CevapID" SET DEFAULT nextval('public."Cevaplar_CevaoID_seq"'::regclass);


--
-- Name: Cevaplar KullaniciD; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevaplar" ALTER COLUMN "KullaniciD" SET DEFAULT nextval('public."Cevaplar_KullanıcıID_seq"'::regclass);


--
-- Name: Cevaplar SoruID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevaplar" ALTER COLUMN "SoruID" SET DEFAULT nextval('public."Cevaplar_SoruID_seq"'::regclass);


--
-- Name: Cevaplar CevapKontrol; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevaplar" ALTER COLUMN "CevapKontrol" SET DEFAULT nextval('public."Cevaplar_CevapKontrol_seq"'::regclass);


--
-- Name: Editor YoneticiID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Editor" ALTER COLUMN "YoneticiID" SET DEFAULT nextval('public."Edıtor_YonetıcıID_seq"'::regclass);


--
-- Name: EtiketTipi EtiketID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."EtiketTipi" ALTER COLUMN "EtiketID" SET DEFAULT nextval('public."EtıketTıpı_EtıketID_seq"'::regclass);


--
-- Name: EtiketTipi EtiketTipID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."EtiketTipi" ALTER COLUMN "EtiketTipID" SET DEFAULT nextval('public."EtıketTıpı_EtıketTıpID_seq"'::regclass);


--
-- Name: Etiketler EtiketID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler" ALTER COLUMN "EtiketID" SET DEFAULT nextval('public."Etiketler_EtıketID_seq"'::regclass);


--
-- Name: Etiketler Adi; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler" ALTER COLUMN "Adi" SET DEFAULT nextval('public."Etiketler_Ad_seq"'::regclass);


--
-- Name: Etiketler SoruID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler" ALTER COLUMN "SoruID" SET DEFAULT nextval('public."Etiketler_SoruID_seq"'::regclass);


--
-- Name: Etiketler EtiketDuzeni; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler" ALTER COLUMN "EtiketDuzeni" SET DEFAULT nextval('public."Etıketler_EtıketDuzenı_seq"'::regclass);


--
-- Name: Goruntulenme ID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme" ALTER COLUMN "ID" SET DEFAULT nextval('public."Goruntulenme_ID_seq"'::regclass);


--
-- Name: Goruntulenme SoruID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme" ALTER COLUMN "SoruID" SET DEFAULT nextval('public."Goruntulenme_SoruID_seq"'::regclass);


--
-- Name: Goruntulenme CevapID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme" ALTER COLUMN "CevapID" SET DEFAULT nextval('public."Goruntulenme_CevapID_seq"'::regclass);


--
-- Name: Goruntulenme YorumID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme" ALTER COLUMN "YorumID" SET DEFAULT nextval('public."Goruntulenme_YorumID_seq"'::regclass);


--
-- Name: KullaniciEtiket EtiketID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciEtiket" ALTER COLUMN "EtiketID" SET DEFAULT nextval('public."KullanıcıEtıket_EtıketID_seq"'::regclass);


--
-- Name: KullaniciEtiket KullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciEtiket" ALTER COLUMN "KullaniciID" SET DEFAULT nextval('public."KullanıcıEtıket_KullanıcıID_seq"'::regclass);


--
-- Name: KullaniciEtiket DuzenlemeYoneticisi; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciEtiket" ALTER COLUMN "DuzenlemeYoneticisi" SET DEFAULT nextval('public."KullanıcıEtıket_DuzenlemeYonetıcısı_seq"'::regclass);


--
-- Name: KullaniciRozet KullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciRozet" ALTER COLUMN "KullaniciID" SET DEFAULT nextval('public."KulanıcıRozet_KullanıcıID_seq"'::regclass);


--
-- Name: KullaniciRozet RozetID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciRozet" ALTER COLUMN "RozetID" SET DEFAULT nextval('public."KulanıcıRozet_RozetID_seq"'::regclass);


--
-- Name: Kullanicilar KullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanicilar" ALTER COLUMN "KullaniciID" SET DEFAULT nextval('public."Kullanıcılar_KullanıcıID_seq"'::regclass);


--
-- Name: Moderator YoneticiID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Moderator" ALTER COLUMN "YoneticiID" SET DEFAULT nextval('public."Moderator_YonetıcıID_seq"'::regclass);


--
-- Name: OyTipi ID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi" ALTER COLUMN "ID" SET DEFAULT nextval('public."OyTıpı_ID_seq"'::regclass);


--
-- Name: OyTipi Ad; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi" ALTER COLUMN "Ad" SET DEFAULT nextval('public."OyTıpı_Ad_seq"'::regclass);


--
-- Name: OyTipi OyID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi" ALTER COLUMN "OyID" SET DEFAULT nextval('public."OyTıpı_OyID_seq"'::regclass);


--
-- Name: OyTipi FeedBackID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi" ALTER COLUMN "FeedBackID" SET DEFAULT nextval('public."OyTıpı_FeedBakID_seq"'::regclass);


--
-- Name: Oylar OyID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar" ALTER COLUMN "OyID" SET DEFAULT nextval('public."Oylar_OyID_seq"'::regclass);


--
-- Name: Oylar KullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar" ALTER COLUMN "KullaniciID" SET DEFAULT nextval('public."Oylar_KullanıcıID_seq"'::regclass);


--
-- Name: Oylar SoruID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar" ALTER COLUMN "SoruID" SET DEFAULT nextval('public."Oylar_SoruID_seq"'::regclass);


--
-- Name: Oylar CevapID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar" ALTER COLUMN "CevapID" SET DEFAULT nextval('public."Oylar_CevapID_seq"'::regclass);


--
-- Name: Rozetler RozetID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Rozetler" ALTER COLUMN "RozetID" SET DEFAULT nextval('public."Rozetler_RozetID_seq"'::regclass);


--
-- Name: SoruFeedback FeedBackID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."SoruFeedback" ALTER COLUMN "FeedBackID" SET DEFAULT nextval('public."SoruFeedback_FeedBackID_seq"'::regclass);


--
-- Name: SoruFeedback SoruID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."SoruFeedback" ALTER COLUMN "SoruID" SET DEFAULT nextval('public."SoruFeedback_SoruID_seq"'::regclass);


--
-- Name: Sorular SoruID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sorular" ALTER COLUMN "SoruID" SET DEFAULT nextval('public."Sorular_SoruID_seq"'::regclass);


--
-- Name: Sorular KullaniciID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sorular" ALTER COLUMN "KullaniciID" SET DEFAULT nextval('public."Sorular_KullanıcıID_seq"'::regclass);


--
-- Name: Sorular SoruDuzeni; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sorular" ALTER COLUMN "SoruDuzeni" SET DEFAULT nextval('public."Sorular_SoruDuzenı_seq"'::regclass);


--
-- Name: Yoneticiler YoneticiID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yoneticiler" ALTER COLUMN "YoneticiID" SET DEFAULT nextval('public."Yöneticiler_YöneticiID_seq"'::regclass);


--
-- Name: Yorumlar YorumID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yorumlar" ALTER COLUMN "YorumID" SET DEFAULT nextval('public."Yorumlar_YorumID_seq"'::regclass);


--
-- Name: Yorumlar CevapID; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yorumlar" ALTER COLUMN "CevapID" SET DEFAULT nextval('public."Yorumlar_CevapID_seq"'::regclass);


--
-- Data for Name: Admin; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Admin" VALUES (3, 'yargıc');
INSERT INTO public."Admin" VALUES (1, 'hakim54');
INSERT INTO public."Admin" VALUES (2, 'kehanet');


--
-- Data for Name: Cevaplar; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Cevaplar" VALUES (2, 'byznrdmr', 2, 'tesekkurler', 1, 1, 1);
INSERT INTO public."Cevaplar" VALUES (3, 'cmzyrt', 4, 'sorun cozuldu', 2, 3, 2);
INSERT INTO public."Cevaplar" VALUES (4, 'fatmaa', 6, 'sorun icin link bırakıyorum', 3, 2, 3);


--
-- Data for Name: Editor; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Editor" VALUES (1);
INSERT INTO public."Editor" VALUES (2);


--
-- Data for Name: EtiketTipi; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."EtiketTipi" VALUES (1, 1);
INSERT INTO public."EtiketTipi" VALUES (4, 2);
INSERT INTO public."EtiketTipi" VALUES (5, 3);


--
-- Data for Name: Etiketler; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Etiketler" VALUES (1, 'proses', 1, 3);
INSERT INTO public."Etiketler" VALUES (5, 'kernel', 1, 3);
INSERT INTO public."Etiketler" VALUES (4, 'cpu', 1, 3);


--
-- Data for Name: Goruntulenme; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Goruntulenme" VALUES (2, 'byznrdmr', 3, 1, 2, 1);
INSERT INTO public."Goruntulenme" VALUES (3, 'cmzyrt', 4, 2, 2, 2);


--
-- Data for Name: KullaniciEtiket; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."KullaniciEtiket" VALUES (1, 1, 1);


--
-- Data for Name: KullaniciRozet; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."KullaniciRozet" VALUES (1, 1);
INSERT INTO public."KullaniciRozet" VALUES (2, 2);
INSERT INTO public."KullaniciRozet" VALUES (3, 3);
INSERT INTO public."KullaniciRozet" VALUES (4, 4);
INSERT INTO public."KullaniciRozet" VALUES (3, 2);
INSERT INTO public."KullaniciRozet" VALUES (3, 4);


--
-- Data for Name: Kullanicilar; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Kullanicilar" VALUES (2, 'Cem', 'OZYURT', 'Aktif', 'cemozyurt@windowslive.com', 'Istanbul', NULL, 'silver', 4, 'Bisiklet', '2018-07-28', '2019-03-23', 26);
INSERT INTO public."Kullanicilar" VALUES (1, 'Beyza', 'DEMIR', 'Pasif', 'byznrrdmr@gmail.com', 'Sakarya', 'Saü bilgisayar mühendisligi 3. sınıf', 'gold', 1, 'IEEE', '2019-09-10', '2019-09-10', 22);
INSERT INTO public."Kullanicilar" VALUES (3, 'Fatma', 'DEMIR', 'Kidemli', 'faaatma@gmail.com', 'Ordu', NULL, 'master', 4.8, 'Kamp', '2003-03-20', '2019-12-09', 21);
INSERT INTO public."Kullanicilar" VALUES (4, 'Omer', 'AKCALI', 'Yeni', 'omer@windowslive.com', 'Canakkale', 'Elektrik muhendisi', 'bronze', 0.5, 'Basketbol', '2020-01-01', '2020-01-01', 23);


--
-- Data for Name: Moderator; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Moderator" VALUES (3);


--
-- Data for Name: OyTipi; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."OyTipi" VALUES (2, 'gecerli', 1, 1);
INSERT INTO public."OyTipi" VALUES (1, 'gecersiz', 1, 1);


--
-- Data for Name: Oylar; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Oylar" VALUES (1, '1004-01-01', 1, 1, 2);


--
-- Data for Name: Rozetler; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Rozetler" VALUES (1, 'gold', '2013-02-04', 'A');
INSERT INTO public."Rozetler" VALUES (2, 'silver', '2013-04-03', 'B');
INSERT INTO public."Rozetler" VALUES (3, 'master', '2013-03-10', 'C');
INSERT INTO public."Rozetler" VALUES (4, 'bronze', '2014-04-05', 'D');


--
-- Data for Name: SoruFeedback; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."SoruFeedback" VALUES (1, '1997-08-01', 1);


--
-- Data for Name: Sorular; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Sorular" VALUES (1, 'Silinmeyen Dosya', 'dosya', '2015-04-09', 3, 1, 1, 1);
INSERT INTO public."Sorular" VALUES (5, 'Isinma Sebepleri', 'cpu', '2017-04-08', 3, 1, 1, 2);
INSERT INTO public."Sorular" VALUES (4, 'Kernel', 'kernel', '2017-04-08', 4, 3, 1, 2);
INSERT INTO public."Sorular" VALUES (2, 'Cakisan Prosesler', 'proses', '2017-04-08', 5, 3, 1, 2);


--
-- Data for Name: Yoneticiler; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Yoneticiler" VALUES (2, 'mehmet', 'ak', 28, 'memo@windowslive.com', 'adana', NULL);
INSERT INTO public."Yoneticiler" VALUES (3, 'zeynep', 'bastık', 26, 'zb@gmail.com', 'kastamonu', 'singer, traveler,blogger');
INSERT INTO public."Yoneticiler" VALUES (1, 'ali', 'turan', 33, 'ali@gmail.com', 'ıstanbul', 'evli,mutlu,cocuklu');


--
-- Data for Name: Yorumlar; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public."Yorumlar" VALUES (1, '2019-04-10', 'tesekkurler', 'byznrdmr', 2);
INSERT INTO public."Yorumlar" VALUES (2, '2018-03-28', 'sorun cozuldu', 'cmzyrt', 3);
INSERT INTO public."Yorumlar" VALUES (3, '2019-05-04', 'sorun icin link bırakıyorum', 'fatmaa', 4);


--
-- Name: Admın_YonetıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Admın_YonetıcıID_seq"', 3, true);


--
-- Name: Cevaplar_CevaoID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Cevaplar_CevaoID_seq"', 21, true);


--
-- Name: Cevaplar_CevapKontrol_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Cevaplar_CevapKontrol_seq"', 1, true);


--
-- Name: Cevaplar_KullanıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Cevaplar_KullanıcıID_seq"', 1, true);


--
-- Name: Cevaplar_SoruID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Cevaplar_SoruID_seq"', 1, true);


--
-- Name: Edıtor_YonetıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Edıtor_YonetıcıID_seq"', 1, true);


--
-- Name: Etiketler_Ad_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Etiketler_Ad_seq"', 1, true);


--
-- Name: Etiketler_EtıketID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Etiketler_EtıketID_seq"', 1, true);


--
-- Name: Etiketler_SoruID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Etiketler_SoruID_seq"', 1, true);


--
-- Name: EtıketTıpı_EtıketID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."EtıketTıpı_EtıketID_seq"', 1, false);


--
-- Name: EtıketTıpı_EtıketTıpID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."EtıketTıpı_EtıketTıpID_seq"', 1, false);


--
-- Name: Etıketler_EtıketDuzenı_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Etıketler_EtıketDuzenı_seq"', 1, true);


--
-- Name: Goruntulenme_CevapID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Goruntulenme_CevapID_seq"', 1, false);


--
-- Name: Goruntulenme_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Goruntulenme_ID_seq"', 3, true);


--
-- Name: Goruntulenme_SoruID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Goruntulenme_SoruID_seq"', 1, false);


--
-- Name: Goruntulenme_YorumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Goruntulenme_YorumID_seq"', 1, false);


--
-- Name: KulanıcıRozet_KullanıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KulanıcıRozet_KullanıcıID_seq"', 1, false);


--
-- Name: KulanıcıRozet_RozetID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KulanıcıRozet_RozetID_seq"', 1, false);


--
-- Name: KullanıcıEtıket_DuzenlemeYonetıcısı_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KullanıcıEtıket_DuzenlemeYonetıcısı_seq"', 1, false);


--
-- Name: KullanıcıEtıket_EtıketID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KullanıcıEtıket_EtıketID_seq"', 1, false);


--
-- Name: KullanıcıEtıket_KullanıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."KullanıcıEtıket_KullanıcıID_seq"', 1, false);


--
-- Name: Kullanıcılar_KullanıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Kullanıcılar_KullanıcıID_seq"', 4, true);


--
-- Name: Moderator_YonetıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Moderator_YonetıcıID_seq"', 1, false);


--
-- Name: OyTıpı_Ad_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyTıpı_Ad_seq"', 1, false);


--
-- Name: OyTıpı_FeedBakID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyTıpı_FeedBakID_seq"', 1, true);


--
-- Name: OyTıpı_ID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyTıpı_ID_seq"', 2, true);


--
-- Name: OyTıpı_OyID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."OyTıpı_OyID_seq"', 1, true);


--
-- Name: Oylar_CevapID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Oylar_CevapID_seq"', 1, false);


--
-- Name: Oylar_KullanıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Oylar_KullanıcıID_seq"', 1, false);


--
-- Name: Oylar_OyID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Oylar_OyID_seq"', 1, false);


--
-- Name: Oylar_SoruID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Oylar_SoruID_seq"', 1, false);


--
-- Name: Rozetler_RozetID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Rozetler_RozetID_seq"', 4, true);


--
-- Name: SoruFeedback_FeedBackID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."SoruFeedback_FeedBackID_seq"', 1, false);


--
-- Name: SoruFeedback_SoruID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."SoruFeedback_SoruID_seq"', 1, false);


--
-- Name: Sorular_KullanıcıID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Sorular_KullanıcıID_seq"', 1, false);


--
-- Name: Sorular_SoruDuzenı_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Sorular_SoruDuzenı_seq"', 1, true);


--
-- Name: Sorular_SoruID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Sorular_SoruID_seq"', 6, true);


--
-- Name: Yorumlar_CevapID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Yorumlar_CevapID_seq"', 1, false);


--
-- Name: Yorumlar_YorumID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Yorumlar_YorumID_seq"', 2, true);


--
-- Name: Yöneticiler_YöneticiID_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public."Yöneticiler_YöneticiID_seq"', 3, true);


--
-- Name: Admin Admın_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin"
    ADD CONSTRAINT "Admın_pkey" PRIMARY KEY ("YoneticiID");


--
-- Name: Cevaplar Cevaplar_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevaplar"
    ADD CONSTRAINT "Cevaplar_pkey" PRIMARY KEY ("CevapID");


--
-- Name: Editor Edıtor_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Editor"
    ADD CONSTRAINT "Edıtor_pkey" PRIMARY KEY ("YoneticiID");


--
-- Name: Etiketler Etiketler_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler"
    ADD CONSTRAINT "Etiketler_pkey" PRIMARY KEY ("EtiketID");


--
-- Name: EtiketTipi EtıketTıpı_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."EtiketTipi"
    ADD CONSTRAINT "EtıketTıpı_pkey" PRIMARY KEY ("EtiketTipID");


--
-- Name: Goruntulenme Goruntulenme_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme"
    ADD CONSTRAINT "Goruntulenme_pkey" PRIMARY KEY ("ID");


--
-- Name: KullaniciRozet KulanıcıRozet_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciRozet"
    ADD CONSTRAINT "KulanıcıRozet_pkey" PRIMARY KEY ("KullaniciID", "RozetID");


--
-- Name: KullaniciEtiket KullanıcıEtıket_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciEtiket"
    ADD CONSTRAINT "KullanıcıEtıket_pkey" PRIMARY KEY ("EtiketID", "KullaniciID");


--
-- Name: Kullanicilar Kullanıcılar_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Kullanicilar"
    ADD CONSTRAINT "Kullanıcılar_pkey" PRIMARY KEY ("KullaniciID");


--
-- Name: Moderator Moderator_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Moderator"
    ADD CONSTRAINT "Moderator_pkey" PRIMARY KEY ("YoneticiID");


--
-- Name: OyTipi OyTıpı_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi"
    ADD CONSTRAINT "OyTıpı_pkey" PRIMARY KEY ("ID");


--
-- Name: Oylar Oylar_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar"
    ADD CONSTRAINT "Oylar_pkey" PRIMARY KEY ("OyID");


--
-- Name: Rozetler Rozetler_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Rozetler"
    ADD CONSTRAINT "Rozetler_pkey" PRIMARY KEY ("RozetID");


--
-- Name: SoruFeedback SoruFeedback_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."SoruFeedback"
    ADD CONSTRAINT "SoruFeedback_pkey" PRIMARY KEY ("FeedBackID");


--
-- Name: Sorular Sorular_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sorular"
    ADD CONSTRAINT "Sorular_pkey" PRIMARY KEY ("SoruID");


--
-- Name: Yorumlar Yorumlar_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yorumlar"
    ADD CONSTRAINT "Yorumlar_pkey" PRIMARY KEY ("YorumID");


--
-- Name: Yoneticiler Yöneticiler_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yoneticiler"
    ADD CONSTRAINT "Yöneticiler_pkey" PRIMARY KEY ("YoneticiID");


--
-- Name: Cevaplar lnk_Admın_Cevaplar; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Cevaplar"
    ADD CONSTRAINT "lnk_Admın_Cevaplar" FOREIGN KEY ("CevapKontrol") REFERENCES public."Admin"("YoneticiID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Goruntulenme lnk_Cevaplar_Goruntulenme; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme"
    ADD CONSTRAINT "lnk_Cevaplar_Goruntulenme" FOREIGN KEY ("CevapID") REFERENCES public."Cevaplar"("CevapID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Oylar lnk_Cevaplar_Oylar; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar"
    ADD CONSTRAINT "lnk_Cevaplar_Oylar" FOREIGN KEY ("CevapID") REFERENCES public."Cevaplar"("CevapID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Yorumlar lnk_Cevaplar_Yorumlar; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Yorumlar"
    ADD CONSTRAINT "lnk_Cevaplar_Yorumlar" FOREIGN KEY ("CevapID") REFERENCES public."Cevaplar"("CevapID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Sorular lnk_Edıtor_Sorular; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sorular"
    ADD CONSTRAINT "lnk_Edıtor_Sorular" FOREIGN KEY ("SoruDuzeni") REFERENCES public."Editor"("YoneticiID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: EtiketTipi lnk_Etıketler_EtıketTıpı; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."EtiketTipi"
    ADD CONSTRAINT "lnk_Etıketler_EtıketTıpı" FOREIGN KEY ("EtiketID") REFERENCES public."Etiketler"("EtiketID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: KullaniciEtiket lnk_Etıketler_KullanıcıEtıket; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciEtiket"
    ADD CONSTRAINT "lnk_Etıketler_KullanıcıEtıket" FOREIGN KEY ("EtiketID") REFERENCES public."Etiketler"("EtiketID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: KullaniciRozet lnk_Kullanıcılar_KulanıcıRozet; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciRozet"
    ADD CONSTRAINT "lnk_Kullanıcılar_KulanıcıRozet" FOREIGN KEY ("KullaniciID") REFERENCES public."Kullanicilar"("KullaniciID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: KullaniciEtiket lnk_Kullanıcılar_KullanıcıEtıket; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciEtiket"
    ADD CONSTRAINT "lnk_Kullanıcılar_KullanıcıEtıket" FOREIGN KEY ("KullaniciID") REFERENCES public."Kullanicilar"("KullaniciID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Oylar lnk_Kullanıcılar_Oylar; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar"
    ADD CONSTRAINT "lnk_Kullanıcılar_Oylar" FOREIGN KEY ("KullaniciID") REFERENCES public."Kullanicilar"("KullaniciID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Sorular lnk_Kullanıcılar_Sorular; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Sorular"
    ADD CONSTRAINT "lnk_Kullanıcılar_Sorular" FOREIGN KEY ("KullaniciID") REFERENCES public."Kullanicilar"("KullaniciID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Etiketler lnk_Moderator_Etıketler; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler"
    ADD CONSTRAINT "lnk_Moderator_Etıketler" FOREIGN KEY ("EtiketDuzeni") REFERENCES public."Moderator"("YoneticiID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: OyTipi lnk_Oylar_OyTıpı; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi"
    ADD CONSTRAINT "lnk_Oylar_OyTıpı" FOREIGN KEY ("OyID") REFERENCES public."Oylar"("OyID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: KullaniciRozet lnk_Rozetler_KulanıcıRozet; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."KullaniciRozet"
    ADD CONSTRAINT "lnk_Rozetler_KulanıcıRozet" FOREIGN KEY ("RozetID") REFERENCES public."Rozetler"("RozetID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: OyTipi lnk_SoruFeedback_OyTıpı; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."OyTipi"
    ADD CONSTRAINT "lnk_SoruFeedback_OyTıpı" FOREIGN KEY ("FeedBackID") REFERENCES public."SoruFeedback"("FeedBackID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Etiketler lnk_Sorular_Etiketler; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Etiketler"
    ADD CONSTRAINT "lnk_Sorular_Etiketler" FOREIGN KEY ("SoruID") REFERENCES public."Sorular"("SoruID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Goruntulenme lnk_Sorular_Goruntulenme; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme"
    ADD CONSTRAINT "lnk_Sorular_Goruntulenme" FOREIGN KEY ("SoruID") REFERENCES public."Sorular"("SoruID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Oylar lnk_Sorular_Oylar; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Oylar"
    ADD CONSTRAINT "lnk_Sorular_Oylar" FOREIGN KEY ("SoruID") REFERENCES public."Sorular"("SoruID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: SoruFeedback lnk_Sorular_SoruFeedback; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."SoruFeedback"
    ADD CONSTRAINT "lnk_Sorular_SoruFeedback" FOREIGN KEY ("SoruID") REFERENCES public."Sorular"("SoruID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Admin lnk_Yonetıcıler_Admın; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Admin"
    ADD CONSTRAINT "lnk_Yonetıcıler_Admın" FOREIGN KEY ("YoneticiID") REFERENCES public."Yoneticiler"("YoneticiID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Editor lnk_Yonetıcıler_Edıtor; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Editor"
    ADD CONSTRAINT "lnk_Yonetıcıler_Edıtor" FOREIGN KEY ("YoneticiID") REFERENCES public."Yoneticiler"("YoneticiID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Moderator lnk_Yonetıcıler_Moderator; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Moderator"
    ADD CONSTRAINT "lnk_Yonetıcıler_Moderator" FOREIGN KEY ("YoneticiID") REFERENCES public."Yoneticiler"("YoneticiID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- Name: Goruntulenme lnk_Yorumlar_Goruntulenme; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public."Goruntulenme"
    ADD CONSTRAINT "lnk_Yorumlar_Goruntulenme" FOREIGN KEY ("YorumID") REFERENCES public."Yorumlar"("YorumID") MATCH FULL ON UPDATE CASCADE ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--

