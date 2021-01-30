-- phpMyAdmin SQL Dump
-- version 4.7.4
-- https://www.phpmyadmin.net/
--
-- Anamakine: 127.0.0.1:3306
-- Üretim Zamanı: 06 May 2018, 18:54:43
-- Sunucu sürümü: 5.7.19
-- PHP Sürümü: 5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `karasu`
--

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `duyuru`
--

DROP TABLE IF EXISTS `duyuru`;
CREATE TABLE IF NOT EXISTS `duyuru` (
  `duyuru_id` int(11) NOT NULL AUTO_INCREMENT,
  `duyuru_baslik` varchar(100) NOT NULL,
  `duyuru_metin` varchar(500) NOT NULL,
  PRIMARY KEY (`duyuru_id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

--
-- Tablo döküm verisi `duyuru`
--

INSERT INTO `duyuru` (`duyuru_id`, `duyuru_baslik`, `duyuru_metin`) VALUES
(1, 'İlk Duyuru', 'Web sitemiz yenilenmiştir'),
(2, 'Tatil Mevsimi Başlıyor', 'duyuru tatil mevsimi başlıyor');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
