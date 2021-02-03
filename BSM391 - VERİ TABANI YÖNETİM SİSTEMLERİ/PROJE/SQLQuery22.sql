CREATE SCHEMA "Personeller";




CREATE TABLE "Personeller"."Personel" ( 
	"personelNo" INT,
	"adi" CHARACTER VARYING(40) NOT NULL,
	"soyadi" CHARACTER VARYING(40) NOT NULL,
	"personelTipi" CHARACTER(1) NOT NULL,
	CONSTRAINT "personelPK" PRIMARY KEY ("personelNo")
);
CREATE TABLE "Personeller"."Danisman" ( 
	"personelNo" INT,
	"sirket" CHARACTER VARYING(40) NOT NULL,
	CONSTRAINT "danismanPK" PRIMARY KEY ("personelNo")
);
CREATE TABLE "Personeller"."SatisTemsilcisi" ( 
	"personelNo" INT,
	"bolge" CHARACTER VARYING(40) NOT NULL,
	CONSTRAINT "satisTemsilcisiPK" PRIMARY KEY ("personelNo")
);