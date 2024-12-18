-- MySQL dump 10.13  Distrib 5.5.28, for Linux (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `id` int(10) unsigned NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `symbol` varchar(10) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  `price` decimal(10,4) unsigned NOT NULL,
  `transaction` tinyint(1) unsigned NOT NULL,
  PRIMARY KEY (`id`,`date`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (14,'2013-03-04 21:49:59','GOOG',1,99.9999,1),(14,'2013-03-04 21:50:46','GOOG',1,99.9999,1),(14,'2013-03-04 21:56:16','GOOG',1,821.5040,1),(14,'2013-03-04 22:05:33','INT',25,37.9800,1),(14,'2013-03-06 21:19:41','GOOG',10000,831.3800,1),(14,'2013-03-06 21:19:48','INT',10000,38.3400,1),(14,'2013-03-06 21:19:54','IBM',10000,208.3800,1),(14,'2013-03-06 21:20:07','INT',10000,38.3400,0),(14,'2013-03-06 22:55:07','GOOG',10000,831.3800,0),(14,'2013-03-06 23:04:21','IBM',10000,208.3800,0),(14,'2013-03-09 14:08:14','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:19','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:21','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:22','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:23','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:24','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:25','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:26','GOOG',10,831.5200,1),(14,'2013-03-09 14:08:27','GOOG',10,831.5200,1),(14,'2013-03-09 14:23:55','GOOG',110,831.5200,0),(14,'2013-03-09 14:39:43','GOOG',10,831.5200,1),(14,'2013-03-09 14:39:53','GOOG',10,831.5200,0);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolio`
--

DROP TABLE IF EXISTS `portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolio` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolio`
--

LOCK TABLES `portfolio` WRITE;
/*!40000 ALTER TABLE `portfolio` DISABLE KEYS */;
INSERT INTO `portfolio` VALUES (2,'AAT',20),(7,'AAT',10000),(7,'GOOG',20000);
/*!40000 ALTER TABLE `portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'caesar','$1$50$GHABNWBNE/o4VL7QjmQ6x0',10000.0000),(2,'cs50','$1$50$ceNa7BV5AoVQqilACNLuC1',10000.0000),(3,'jharvard','$1$50$RX3wnAMNrGIbgzbRYrxM1/',10000.0000),(4,'malan','$1$HA$azTGIMVlmPi9W9Y12cYSj/',10000.0000),(5,'nate','$1$50$sUyTaTbiSKVPZCpjJckan0',10000.0000),(6,'rbowden','$1$50$lJS9HiGK6sphej8c4bnbX.',10000.0000),(7,'skroob','$1$50$euBi4ugiJmbpIbvTTfmfI.',10000.0000),(8,'tmacwilliam','$1$50$91ya4AroFPepdLpiX.bdP1',10000.0000),(9,'zamyla','$1$50$Suq.MOtQj51maavfKvFsW1',10000.0000),(14,'banksie','$1$uVNDZcv4$fpNqtTm.MqDnWhKIH6d6b.',1764351091486.1921);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-03-09  9:59:55
