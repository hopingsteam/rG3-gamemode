/*
Navicat MySQL Data Transfer

Source Server         : localhost
Source Server Version : 50617
Source Host           : localhost:3306
Source Database       : samp

Target Server Type    : MYSQL
Target Server Version : 50617
File Encoding         : 65001

Date: 2015-06-02 10:31:42
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `ads`
-- ----------------------------
DROP TABLE IF EXISTS `ads`;
CREATE TABLE `ads` (
  `ID` int(4) NOT NULL AUTO_INCREMENT,
  `user` varchar(25) NOT NULL,
  `message` varchar(128) NOT NULL,
  `phone` varchar(15) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of ads
-- ----------------------------

-- ----------------------------
-- Table structure for `bans`
-- ----------------------------
DROP TABLE IF EXISTS `bans`;
CREATE TABLE `bans` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Player` varchar(50) DEFAULT NULL,
  `Admin` varchar(50) DEFAULT NULL,
  `BannedDate` varchar(50) DEFAULT NULL,
  `reason` varchar(50) DEFAULT NULL,
  `ip` varchar(50) DEFAULT '0.0.0.0',
  `time` int(3) DEFAULT NULL,
  `UD` int(3) DEFAULT '0',
  `UM` int(3) DEFAULT '0',
  `UY` int(3) DEFAULT '0',
  `UH` int(3) DEFAULT '0',
  `UMi` int(3) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=337 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of bans
-- ----------------------------

-- ----------------------------
-- Table structure for `bizz`
-- ----------------------------
DROP TABLE IF EXISTS `bizz`;
CREATE TABLE `bizz` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Owner` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'NoOne',
  `Message` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'NoOne',
  `Owned` int(2) NOT NULL DEFAULT '0',
  `EntranceX` float(11,4) NOT NULL DEFAULT '0.0000',
  `EntranceY` float(11,4) NOT NULL DEFAULT '0.0000',
  `EntranceZ` float(11,4) NOT NULL DEFAULT '0.0000',
  `ExitX` float(11,4) NOT NULL DEFAULT '0.0000',
  `ExitY` float(11,4) NOT NULL DEFAULT '0.0000',
  `ExitZ` float(11,4) NOT NULL DEFAULT '0.0000',
  `LevelNeeded` int(3) NOT NULL DEFAULT '5',
  `BuyPrice` int(5) NOT NULL DEFAULT '5000000',
  `EntranceCost` int(5) NOT NULL DEFAULT '0',
  `Till` int(5) NOT NULL DEFAULT '0',
  `Locked` int(2) NOT NULL DEFAULT '0',
  `Interior` int(5) NOT NULL DEFAULT '0',
  `Products` int(5) NOT NULL DEFAULT '0',
  `MaxProducts` int(5) NOT NULL DEFAULT '500',
  `PriceProd` int(5) NOT NULL DEFAULT '1',
  `GunPrice` int(5) NOT NULL DEFAULT '0',
  `Virtual` int(5) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=25 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of bizz
-- ----------------------------
INSERT INTO `bizz` VALUES ('1', 'The State', 'LSPD Armoury', '1', '1568.6074', '-1690.0605', '6.2188', '246.3760', '109.2460', '1003.2200', '5', '500000', '10', '0', '0', '10', '500', '500', '1', '100', '0');
INSERT INTO `bizz` VALUES ('2', 'The State', '24/7', '1', '999.6135', '-920.1354', '42.3281', '-26.6916', '-55.7149', '1003.5469', '5', '5000000', '0', '0', '0', '6', '446', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('3', 'AldoKenzo', '24/7', '1', '1315.4924', '-898.9666', '39.5781', '-26.6916', '-55.7149', '1003.5469', '5', '70000', '1', '4', '1', '6', '449', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('4', '[HD]AlfabeT', '24/7', '1', '1352.1144', '-1758.3259', '13.5078', '-26.6916', '-55.7149', '1003.5469', '1', '155000', '10', '109', '1', '6', '278', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('5', 'Alex_Manole', '24/7', '1', '1832.5122', '-1842.4799', '13.5781', '-26.6916', '-55.7149', '1003.5469', '5', '45000', '0', '0', '0', '6', '251', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('6', 'The State', 'Burger Shot', '1', '811.3170', '-1616.0223', '13.5469', '375.9625', '-65.8168', '1001.5078', '5', '5000000', '0', '0', '0', '10', '489', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('7', 'alquaida', 'Burger Shot', '1', '1199.3969', '-919.3001', '43.1135', '375.9625', '-65.8168', '1001.5078', '7', '1', '0', '0', '1', '10', '474', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('8', 'Ovi', 'Cluckin Bell', '1', '927.1707', '-1352.9222', '13.3767', '369.5795', '-4.4872', '1001.8588', '5', '30000', '0', '0', '1', '9', '485', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('9', 'The State', 'Cluckin Bell', '1', '2420.9607', '-1508.9200', '24.0000', '369.5795', '-4.4872', '1001.8588', '5', '5000000', '0', '0', '0', '9', '496', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('10', 'The State', 'Cluckin Bell', '1', '2397.9683', '-1898.3358', '13.5469', '369.5795', '-4.4872', '1001.8588', '5', '5000000', '0', '0', '0', '9', '499', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('11', 'The State', 'Well Stacked Pizza', '1', '2104.6582', '-1806.4636', '13.5547', '373.8256', '-117.2709', '1001.4995', '5', '5000000', '0', '0', '0', '5', '454', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('12', 'The State', 'Ten Green Bottles', '1', '2308.7117', '-1643.8337', '14.8270', '501.9809', '-69.1501', '998.7578', '5', '5000000', '0', '0', '0', '11', '460', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('13', 'The State', 'Alhambra', '1', '1835.6575', '-1682.5555', '13.3806', '493.3909', '-22.7227', '1000.6796', '5', '5000000', '0', '0', '0', '17', '407', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('14', 'The State', 'The Pig Pen', '1', '2421.5420', '-1220.5344', '25.4782', '1204.8099', '-11.5867', '1000.9218', '5', '5000000', '0', '0', '0', '2', '494', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('15', 'The State', 'Binco', '1', '2244.3389', '-1665.5347', '15.4766', '207.7379', '-109.0199', '1005.1328', '5', '5000000', '0', '0', '0', '15', '205', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('16', 'The State', 'Sub Urban', '1', '2112.7458', '-1212.2916', '23.9641', '203.7779', '-48.4923', '1001.8046', '5', '5000000', '0', '0', '0', '1', '461', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('17', 'The State', 'Pro Laps', '1', '500.0846', '-1359.3816', '16.2598', '207.0549', '-138.8049', '1003.5078', '5', '5000000', '0', '0', '0', '3', '483', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('18', 'The State', 'Victim', '1', '460.5180', '-1500.8820', '31.0580', '226.2939', '-7.4315', '1002.2109', '5', '5000000', '0', '0', '0', '5', '490', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('19', 'The State', 'Zip', '1', '1456.8594', '-1138.0544', '23.9744', '161.3910', '-93.1591', '1001.8040', '5', '5000000', '0', '0', '0', '0', '430', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('20', 'The State', 'Didier Sachs', '1', '453.3484', '-1478.2844', '30.8144', '204.3329', '-166.6940', '1000.5234', '5', '5000000', '0', '0', '0', '14', '492', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('21', 'The State', 'Gym', '1', '2229.3171', '-1722.0303', '13.5686', '772.1119', '-3.8986', '1000.7288', '5', '5000000', '0', '0', '0', '5', '455', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('22', 'The State', 'Bank of Los Santos', '1', '1459.6661', '-1012.2031', '26.8438', '2315.9529', '-1.6118', '26.7421', '5', '1000000', '0', '10', '0', '0', '9663', '500', '1', '0', '0');
INSERT INTO `bizz` VALUES ('23', 'The State', 'Gun Shop Los Santos', '1', '1792.0065', '-1163.7094', '23.8281', '286.1489', '-40.6443', '1001.5156', '5', '1400000', '0', '0', '0', '1', '9870', '500', '1', '10', '0');
INSERT INTO `bizz` VALUES ('24', 'The State', 'Well Stacked Pizza', '1', '1367.5267', '248.3228', '19.5669', '373.8256', '-117.2709', '1001.4995', '5', '5000000', '0', '0', '0', '5', '466', '500', '1', '0', '0');

-- ----------------------------
-- Table structure for `cars`
-- ----------------------------
DROP TABLE IF EXISTS `cars`;
CREATE TABLE `cars` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Model` int(11) NOT NULL,
  `Locationx` float NOT NULL,
  `Locationy` float NOT NULL,
  `Locationz` float NOT NULL,
  `Angle` float NOT NULL,
  `ColorOne` int(11) NOT NULL,
  `ColorTwo` int(11) NOT NULL,
  `Owner` varchar(25) NOT NULL DEFAULT 'Dealership',
  `Value` int(11) NOT NULL,
  `License` varchar(15) NOT NULL DEFAULT 'LS-01-RGM',
  `Alarm` int(11) NOT NULL,
  `Lockk` int(11) NOT NULL,
  `mod0` int(11) NOT NULL DEFAULT '0',
  `mod1` int(11) NOT NULL DEFAULT '0',
  `mod2` int(11) NOT NULL DEFAULT '0',
  `mod3` int(11) NOT NULL DEFAULT '0',
  `mod4` int(11) NOT NULL DEFAULT '0',
  `mod5` int(11) NOT NULL DEFAULT '0',
  `mod6` int(11) NOT NULL DEFAULT '0',
  `mod7` int(11) NOT NULL DEFAULT '0',
  `mod8` int(11) NOT NULL DEFAULT '0',
  `mod9` int(11) NOT NULL DEFAULT '0',
  `mod10` int(11) NOT NULL DEFAULT '0',
  `mod11` int(11) NOT NULL DEFAULT '0',
  `mod12` int(11) NOT NULL DEFAULT '0',
  `mod13` int(11) NOT NULL DEFAULT '0',
  `paintjob` int(11) NOT NULL DEFAULT '0',
  `KM` float(11,0) NOT NULL DEFAULT '0',
  `Userid` int(11) NOT NULL DEFAULT '0',
  `Confiscated` int(2) NOT NULL,
  `Spawned` int(2) NOT NULL,
  `Special` int(2) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=242 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of cars
-- ----------------------------
INSERT INTO `cars` VALUES ('1', '541', '1007.33', '-663.686', '120.77', '31.3337', '1', '0', 'Boby.Negrean', '0', 'Boby', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '14', '2299', '0', '295', '1');
INSERT INTO `cars` VALUES ('2', '541', '1909.52', '-2014.41', '13.1713', '0.888037', '1', '0', 'AldoKenzo', '0', 'AR 07 NMT', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '28', '2326', '0', '0', '1');
INSERT INTO `cars` VALUES ('3', '411', '1438', '-1763.29', '13.274', '210.622', '211', '226', 'ScoFieLd94', '0', 'NewCar', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '233', '2320', '0', '296', '1');
INSERT INTO `cars` VALUES ('4', '411', '1482.9', '-1526.19', '17.7694', '7.26785', '211', '211', 'Catalin_Toma', '0', 'NewCar', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '67', '2309', '0', '0', '1');
INSERT INTO `cars` VALUES ('5', '411', '1827.14', '-1847.19', '13.2203', '359.436', '6', '6', 'anonimus', '0', 'B 67 MCM', '0', '0', '0', '0', '0', '0', '0', '1010', '0', '1085', '0', '1087', '0', '0', '0', '0', '0', '289', '2303', '0', '0', '1');
INSERT INTO `cars` VALUES ('6', '541', '1878.24', '-2060.37', '13.1664', '270.435', '211', '222', 'Robert_Andrei', '0', 'NewCar', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '164', '2307', '0', '0', '1');
INSERT INTO `cars` VALUES ('7', '541', '757.075', '-1368.07', '13.1379', '268.665', '245', '228', '[HD]AlfabeT', '0', '#PrajealaHD', '0', '1', '0', '0', '0', '0', '0', '1010', '0', '1098', '0', '0', '0', '0', '0', '0', '0', '50', '2302', '0', '297', '1');
INSERT INTO `cars` VALUES ('9', '411', '745.143', '-1334.03', '13.2685', '181.116', '715351499', '1', 'Kavarna', '0', 'NewCar', '0', '1', '0', '0', '0', '0', '0', '1010', '0', '1082', '0', '0', '0', '0', '0', '0', '0', '147', '2310', '0', '299', '1');
INSERT INTO `cars` VALUES ('8', '541', '1489.03', '-1529.29', '16.8849', '90.2157', '128', '1', 'Maurice', '0', 'NewCar', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '105', '2298', '0', '298', '1');

-- ----------------------------
-- Table structure for `dsveh`
-- ----------------------------
DROP TABLE IF EXISTS `dsveh`;
CREATE TABLE `dsveh` (
  `ID` int(2) NOT NULL AUTO_INCREMENT,
  `Model` int(11) NOT NULL,
  `Price` int(11) NOT NULL DEFAULT '1',
  `Stock` int(2) NOT NULL DEFAULT '-1',
  `Doors` int(3) NOT NULL DEFAULT '1',
  `Type` varchar(25) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'Unknown',
  `MaxSpeed` int(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=75 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of dsveh
-- ----------------------------
INSERT INTO `dsveh` VALUES ('1', '418', '10000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('2', '404', '12000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('3', '466', '15000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('4', '547', '16000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('5', '474', '18000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('6', '549', '21000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('7', '526', '22000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('8', '401', '25000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('9', '410', '25000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('10', '420', '25000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('11', '400', '27000', '-1', '4', 'Off Road', '0');
INSERT INTO `dsveh` VALUES ('12', '527', '27000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('13', '516', '28000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('14', '467', '30000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('15', '546', '30000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('16', '576', '35000', '-1', '2', 'Lowrider', '0');
INSERT INTO `dsveh` VALUES ('17', '436', '35000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('18', '479', '37000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('19', '550', '40000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('20', '542', '44000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('21', '496', '50000', '-1', '2', 'Sport', '0');
INSERT INTO `dsveh` VALUES ('22', '419', '50000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('23', '585', '52000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('24', '491', '53000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('25', '554', '55000', '-1', '2', 'Industrial', '0');
INSERT INTO `dsveh` VALUES ('26', '518', '57000', '-1', '2', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('27', '458', '57000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('28', '540', '60000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('29', '529', '60000', '-1', '4', 'Saloons', '0');
INSERT INTO `dsveh` VALUES ('30', '421', '65000', '-1', '4', 'Saloons', '140');
INSERT INTO `dsveh` VALUES ('31', '551', '65000', '-1', '4', 'Saloons', '1');
INSERT INTO `dsveh` VALUES ('32', '500', '70000', '-1', '2', 'Off Road', '110');
INSERT INTO `dsveh` VALUES ('33', '517', '75000', '-1', '2', 'Saloons', '1');
INSERT INTO `dsveh` VALUES ('34', '439', '80000', '-1', '2', 'Convertibles', '149');
INSERT INTO `dsveh` VALUES ('35', '566', '90000', '-1', '4', 'Lowrider', '173');
INSERT INTO `dsveh` VALUES ('36', '603', '100000', '-1', '2', 'Sport', '186');
INSERT INTO `dsveh` VALUES ('37', '426', '120000', '-1', '4', 'Saloons', '184');
INSERT INTO `dsveh` VALUES ('38', '589', '125000', '-1', '2', 'Sport', '156');
INSERT INTO `dsveh` VALUES ('39', '507', '130000', '-1', '4', 'Saloons', '1');
INSERT INTO `dsveh` VALUES ('40', '580', '140000', '-1', '4', 'Saloons', '1');
INSERT INTO `dsveh` VALUES ('41', '412', '140000', '-1', '2', 'Lowrider', '149');
INSERT INTO `dsveh` VALUES ('42', '561', '145000', '-1', '4', 'Saloons', '140');
INSERT INTO `dsveh` VALUES ('43', '575', '150000', '-1', '1', 'Lowrider', '1');
INSERT INTO `dsveh` VALUES ('44', '558', '160000', '-1', '2', 'Sport', '176');
INSERT INTO `dsveh` VALUES ('45', '535', '160000', '-1', '2', 'Lowrider', '1');
INSERT INTO `dsveh` VALUES ('46', '534', '170000', '-1', '2', 'Lowrider', '1');
INSERT INTO `dsveh` VALUES ('47', '579', '200000', '-1', '4', 'Off Road', '1');
INSERT INTO `dsveh` VALUES ('48', '489', '220000', '-1', '2', 'Off Road', '1');
INSERT INTO `dsveh` VALUES ('49', '587', '240000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('50', '536', '250000', '-1', '2', 'Lowrider', '1');
INSERT INTO `dsveh` VALUES ('51', '567', '260000', '-1', '2', 'Lowrider', '1');
INSERT INTO `dsveh` VALUES ('52', '475', '290000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('53', '506', '320000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('54', '602', '370000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('55', '565', '400000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('56', '559', '450000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('57', '477', '510000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('58', '480', '580000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('59', '429', '700000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('60', '402', '770000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('61', '560', '840000', '-1', '4', 'Saloons', '1');
INSERT INTO `dsveh` VALUES ('62', '415', '900000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('63', '451', '1100000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('64', '541', '1400000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('65', '411', '1800000', '-1', '2', 'Sport', '1');
INSERT INTO `dsveh` VALUES ('66', '586', '125000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('67', '471', '150000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('68', '468', '175000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('69', '581', '300000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('70', '463', '350000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('71', '521', '400000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('72', '522', '800000', '-1', '1', 'Bikes', '1');
INSERT INTO `dsveh` VALUES ('73', '519', '2000000', '-1', '1', 'Airplane', '1');
INSERT INTO `dsveh` VALUES ('74', '487', '3000000', '-1', '1', 'Helicopter', '1');

-- ----------------------------
-- Table structure for `houses`
-- ----------------------------
DROP TABLE IF EXISTS `houses`;
CREATE TABLE `houses` (
  `id` int(11) NOT NULL,
  `Owner` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'The State',
  `Entrancex` float(16,4) NOT NULL DEFAULT '0.0000',
  `Entrancey` float(16,4) NOT NULL DEFAULT '0.0000',
  `Entrancez` float(16,4) NOT NULL DEFAULT '0.0000',
  `Exitx` float(16,4) NOT NULL DEFAULT '0.0000',
  `Exity` float(16,4) NOT NULL DEFAULT '0.0000',
  `Exitz` float(16,4) NOT NULL DEFAULT '0.0000',
  `Health` int(50) NOT NULL,
  `Armour` int(50) NOT NULL,
  `Value` int(50) NOT NULL,
  `Int` int(50) NOT NULL,
  `Lockk` int(50) NOT NULL,
  `Owned` int(50) NOT NULL,
  `Rent` int(50) NOT NULL,
  `Rentabil` int(50) NOT NULL,
  `Takings` int(50) NOT NULL,
  `Date` int(50) NOT NULL,
  `Level` int(11) NOT NULL DEFAULT '0',
  `Drugs` int(50) NOT NULL DEFAULT '0',
  `Materials` int(50) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of houses
-- ----------------------------
INSERT INTO `houses` VALUES ('1', 'Boby.Negrean', '980.3714', '-677.3346', '121.9763', '225.6800', '1021.4500', '1084.0200', '0', '0', '100', '7', '1', '1', '1', '1', '37', '0', '1', '0', '0');
INSERT INTO `houses` VALUES ('2', 'Maurice', '1980.3799', '-1718.9583', '17.0303', '-260.4900', '1456.7500', '1084.3700', '0', '0', '1', '4', '0', '1', '0', '0', '0', '0', '1', '0', '0');

-- ----------------------------
-- Table structure for `infos`
-- ----------------------------
DROP TABLE IF EXISTS `infos`;
CREATE TABLE `infos` (
  `ID` int(2) NOT NULL AUTO_INCREMENT,
  `users` int(11) NOT NULL,
  `banned` int(11) NOT NULL,
  `newestacc` varchar(25) NOT NULL,
  `recorddate` varchar(20) NOT NULL,
  `recordnumber` int(4) NOT NULL,
  `tax` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of infos
-- ----------------------------
INSERT INTO `infos` VALUES ('1', '844', '43', 'Soap', '28.06.2014 17:29', '62', '10');

-- ----------------------------
-- Table structure for `log_abc`
-- ----------------------------
DROP TABLE IF EXISTS `log_abc`;
CREATE TABLE `log_abc` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `log` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=18699 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_abc
-- ----------------------------

-- ----------------------------
-- Table structure for `log_clear`
-- ----------------------------
DROP TABLE IF EXISTS `log_clear`;
CREATE TABLE `log_clear` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `admin` varchar(256) NOT NULL,
  `name` varchar(256) NOT NULL,
  `reason` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=363 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_clear
-- ----------------------------

-- ----------------------------
-- Table structure for `log_faction`
-- ----------------------------
DROP TABLE IF EXISTS `log_faction`;
CREATE TABLE `log_faction` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `faction` int(3) NOT NULL DEFAULT '0',
  `leader` varchar(256) NOT NULL,
  `name` varchar(256) NOT NULL,
  `action` varchar(256) NOT NULL DEFAULT '0',
  `reason` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=532 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_faction
-- ----------------------------

-- ----------------------------
-- Table structure for `log_flood`
-- ----------------------------
DROP TABLE IF EXISTS `log_flood`;
CREATE TABLE `log_flood` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` varchar(256) NOT NULL,
  `log` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=492 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of log_flood
-- ----------------------------

-- ----------------------------
-- Table structure for `log_kick`
-- ----------------------------
DROP TABLE IF EXISTS `log_kick`;
CREATE TABLE `log_kick` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `admin` varchar(256) NOT NULL,
  `name` varchar(256) NOT NULL,
  `reason` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=508 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_kick
-- ----------------------------

-- ----------------------------
-- Table structure for `log_login`
-- ----------------------------
DROP TABLE IF EXISTS `log_login`;
CREATE TABLE `log_login` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(256) NOT NULL,
  `ip` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  `country` varchar(30) NOT NULL,
  `city` varchar(30) NOT NULL,
  `isp` varchar(30) NOT NULL,
  `type` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14066 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_login
-- ----------------------------

-- ----------------------------
-- Table structure for `log_pay`
-- ----------------------------
DROP TABLE IF EXISTS `log_pay`;
CREATE TABLE `log_pay` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `person` varchar(256) NOT NULL,
  `reciever` varchar(256) NOT NULL,
  `amount` int(3) NOT NULL,
  `time` varchar(256) NOT NULL,
  `ipperson` varchar(256) NOT NULL,
  `ipreciever` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14255 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_pay
-- ----------------------------

-- ----------------------------
-- Table structure for `log_safebox`
-- ----------------------------
DROP TABLE IF EXISTS `log_safebox`;
CREATE TABLE `log_safebox` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `faction` int(3) NOT NULL DEFAULT '0',
  `leader` varchar(256) NOT NULL,
  `name` varchar(256) NOT NULL,
  `action` varchar(256) NOT NULL DEFAULT '0',
  `reason` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=729 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_safebox
-- ----------------------------

-- ----------------------------
-- Table structure for `log_transfer`
-- ----------------------------
DROP TABLE IF EXISTS `log_transfer`;
CREATE TABLE `log_transfer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `person` varchar(256) NOT NULL,
  `reciever` varchar(256) NOT NULL,
  `amount` int(3) NOT NULL,
  `time` varchar(256) NOT NULL,
  `ipperson` varchar(256) NOT NULL,
  `ipreciever` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=348 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_transfer
-- ----------------------------

-- ----------------------------
-- Table structure for `log_unwarn`
-- ----------------------------
DROP TABLE IF EXISTS `log_unwarn`;
CREATE TABLE `log_unwarn` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `admin` varchar(256) NOT NULL,
  `name` varchar(256) NOT NULL,
  `reason` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_unwarn
-- ----------------------------

-- ----------------------------
-- Table structure for `log_warn`
-- ----------------------------
DROP TABLE IF EXISTS `log_warn`;
CREATE TABLE `log_warn` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `admin` varchar(256) NOT NULL,
  `name` varchar(256) NOT NULL,
  `reason` varchar(256) NOT NULL,
  `time` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of log_warn
-- ----------------------------

-- ----------------------------
-- Table structure for `members`
-- ----------------------------
DROP TABLE IF EXISTS `members`;
CREATE TABLE `members` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL,
  `email` varchar(50) NOT NULL,
  `password` varchar(128) NOT NULL,
  `salt` varchar(128) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of members
-- ----------------------------
INSERT INTO `members` VALUES ('1', 'Maurice', 'matragunamihai97@gmail.com', '3c64685a6f39de05be4cc25002bcb74ff1ec0fd7a6d393a7f03bfa85f4e64378c91d177b6239822c635ed17f6618a8e9d660fbda736fd80f8edf742719e7420d', 'q');

-- ----------------------------
-- Table structure for `pecos`
-- ----------------------------
DROP TABLE IF EXISTS `pecos`;
CREATE TABLE `pecos` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Owner` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'NoOne',
  `Message` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'NoOne',
  `Owned` int(2) NOT NULL DEFAULT '0',
  `EntranceX` float(11,4) NOT NULL DEFAULT '0.0000',
  `EntranceY` float(11,4) NOT NULL DEFAULT '0.0000',
  `EntranceZ` float(11,4) NOT NULL DEFAULT '0.0000',
  `ExitX` float(11,4) NOT NULL DEFAULT '0.0000',
  `ExitY` float(11,4) NOT NULL DEFAULT '0.0000',
  `ExitZ` float(11,4) NOT NULL DEFAULT '0.0000',
  `LevelNeeded` int(3) NOT NULL DEFAULT '5',
  `BuyPrice` int(5) NOT NULL DEFAULT '5000000',
  `EntranceCost` int(5) NOT NULL DEFAULT '0',
  `Till` int(5) NOT NULL DEFAULT '0',
  `Locked` int(2) NOT NULL DEFAULT '0',
  `Products` int(5) NOT NULL DEFAULT '500',
  `MaxProducts` int(5) NOT NULL DEFAULT '500',
  `PriceProd` int(5) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of pecos
-- ----------------------------
INSERT INTO `pecos` VALUES ('1', 'The State', 'Welcome', '1', '1929.1876', '-1776.3684', '13.5469', '1940.9293', '-1773.1665', '13.6406', '5', '500000', '5', '9900', '0', '48020', '50000', '1');
INSERT INTO `pecos` VALUES ('2', 'The State', 'Welcome', '1', '1024.4878', '-944.6080', '42.5360', '1004.1646', '-937.5211', '42.3281', '5', '5000000', '10', '17960', '0', '48204', '50000', '1');
INSERT INTO `pecos` VALUES ('3', 'The State', 'Welcome', '1', '655.7781', '-565.5521', '16.3359', '655.5915', '-565.3960', '16.3359', '5', '5000000', '5', '500', '0', '49900', '50000', '1');
INSERT INTO `pecos` VALUES ('4', 'The State', 'Welcome', '1', '-82.6904', '-1179.0974', '1.9499', '-91.0348', '-1169.7195', '2.4157', '5', '5000000', '5', '2950', '0', '49410', '50000', '1');
INSERT INTO `pecos` VALUES ('5', 'The State', 'Welcome', '1', '2117.1667', '896.9264', '11.1797', '2114.5344', '919.9037', '10.8203', '5', '5000000', '5', '715', '0', '49857', '50000', '1');
INSERT INTO `pecos` VALUES ('6', 'The State', 'Welcome', '1', '-2420.0908', '969.8356', '45.2969', '-2410.0381', '970.7485', '45.4258', '5', '5000000', '5', '0', '0', '50000', '50000', '1');
INSERT INTO `pecos` VALUES ('7', 'The State', 'Welcome', '1', '-1600.0457', '-2703.3247', '48.5391', '-1605.2699', '-2711.2881', '48.9453', '5', '5000000', '5', '0', '0', '50000', '50000', '1');
INSERT INTO `pecos` VALUES ('8', 'The State', 'Welcome', '1', '1396.4240', '459.2459', '20.1956', '1382.7076', '460.4341', '20.0656', '5', '5000000', '5', '55', '0', '49989', '50000', '1');

-- ----------------------------
-- Table structure for `safeboxs`
-- ----------------------------
DROP TABLE IF EXISTS `safeboxs`;
CREATE TABLE `safeboxs` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Money` int(11) NOT NULL,
  `Drugs` int(11) NOT NULL,
  `Mats` int(11) NOT NULL,
  `Members` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of safeboxs
-- ----------------------------
INSERT INTO `safeboxs` VALUES ('1', '1', '0', '0', '36');
INSERT INTO `safeboxs` VALUES ('2', '156219', '146', '980', '78');
INSERT INTO `safeboxs` VALUES ('3', '2989', '82', '160', '57');
INSERT INTO `safeboxs` VALUES ('4', '220004', '0', '0', '19');
INSERT INTO `safeboxs` VALUES ('5', '0', '0', '0', '7');
INSERT INTO `safeboxs` VALUES ('6', '50001', '0', '0', '21');
INSERT INTO `safeboxs` VALUES ('7', '22000', '0', '0', '23');

-- ----------------------------
-- Table structure for `sbizz`
-- ----------------------------
DROP TABLE IF EXISTS `sbizz`;
CREATE TABLE `sbizz` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Owner` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'NoOne',
  `Message` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'NoOne',
  `Extortion` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'No-One',
  `Owned` int(11) NOT NULL DEFAULT '0',
  `EntranceX` varchar(16) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT '0',
  `EntranceY` varchar(16) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT '0',
  `EntranceZ` varchar(16) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT '0',
  `LevelNeeded` int(11) NOT NULL DEFAULT '5',
  `BuyPrice` int(11) NOT NULL DEFAULT '5000000',
  `EntranceCost` int(11) NOT NULL DEFAULT '0',
  `Till` int(11) NOT NULL DEFAULT '0',
  `Locked` int(11) NOT NULL DEFAULT '0',
  `Interior` int(11) NOT NULL DEFAULT '0',
  `Products` int(11) NOT NULL DEFAULT '0',
  `MaxProducts` int(11) NOT NULL DEFAULT '500',
  `PriceProd` int(11) NOT NULL DEFAULT '1',
  `GunPrice` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of sbizz
-- ----------------------------
INSERT INTO `sbizz` VALUES ('1', 'The State', 'Car Rent Los Santos', 'No-one', '1', '1111.855469', '-1792.875488', '16.593750', '5', '500000', '0', '0', '0', '0', '500', '500', '50', '1000');
INSERT INTO `sbizz` VALUES ('2', 'The State', 'Bike Rent Los Santos', 'No-one', '1', '1222.038330', '-1812.330078', '16.593750', '5', '500000', '0', '0', '0', '0', '500', '500', '50', '1');
INSERT INTO `sbizz` VALUES ('3', 'The State', 'B', 'No-one', '1', '1154.330810', '-1457.950683', '15.796875', '5', '500000', '1', '0', '0', '0', '500', '500', '50', '1000');
INSERT INTO `sbizz` VALUES ('4', 'The State', 'B', 'No-one', '1', '-1721.916992', '-118.680747', '3.548918', '5', '500000', '10', '0', '0', '0', '500', '500', '50', '0');
INSERT INTO `sbizz` VALUES ('5', 'The State', 'B', 'Nimeni', '1', '-2521.005859', '-623.331176', '132.768997', '5', '500000', '10', '929509', '0', '0', '400', '500', '50', '99999');
INSERT INTO `sbizz` VALUES ('6', 'The State', 'B', 'No-one', '1', '1102.415649', '-1458.091552', '15.796875', '5', '500000', '0', '0', '0', '0', '500', '500', '50', '0');
INSERT INTO `sbizz` VALUES ('7', 'The State', 'House Upgrade', 'No-one', '1', '2351.455078', '-1412.284912', '23.992416', '5', '500000', '10', '0', '0', '0', '493', '500', '50', '2');
INSERT INTO `sbizz` VALUES ('8', 'The State', 'CNN Los Santos', 'No-one', '1', '845.007446', '-1046.207397', '25.010288', '5', '500000', '0', '0', '0', '0', '500', '500', '1', '0');
INSERT INTO `sbizz` VALUES ('9', 'The State', 'Car Upgrade', 'No-one', '1', '2510.600097', '-1468.199951', '24.023899', '5', '500000', '0', '0', '0', '0', '280', '500', '50', '10000');
INSERT INTO `sbizz` VALUES ('10', 'The State', 'Phone Company', 'No-one', '1', '1154.729736', '-1440.112060', '15.796875', '5', '500000', '0', '0', '0', '0', '500', '500', '50', '0');
INSERT INTO `sbizz` VALUES ('11', 'The State', 'Paintball Arena', 'No-one', '1', '1310.126586', '-1367.812255', '13.540800', '5', '500000', '0', '0', '0', '0', '499', '500', '50', '100');
INSERT INTO `sbizz` VALUES ('12', 'The State', 'B', 'No-one', '1', '2281.5386', '-2364.6279', '13.5469', '5', '500000', '0', '0', '0', '0', '499', '500', '50', '9999');

-- ----------------------------
-- Table structure for `staticveh`
-- ----------------------------
DROP TABLE IF EXISTS `staticveh`;
CREATE TABLE `staticveh` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Model` int(4) NOT NULL DEFAULT '0',
  `Locationx` float NOT NULL,
  `Locationy` float NOT NULL,
  `Locationz` float NOT NULL,
  `Angle` float NOT NULL,
  `ColorOne` int(4) NOT NULL,
  `ColorTwo` int(4) NOT NULL,
  `RespawnDelay` int(7) NOT NULL DEFAULT '0',
  `Special` int(2) NOT NULL DEFAULT '0',
  `Faction` int(2) NOT NULL DEFAULT '0',
  `Job` int(2) NOT NULL DEFAULT '0',
  `Rank` int(2) NOT NULL DEFAULT '0',
  `License` varchar(25) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL DEFAULT 'THE STATE',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=295 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of staticveh
-- ----------------------------
INSERT INTO `staticveh` VALUES ('1', '567', '2516', '-1671.74', '13.6838', '64.202', '234', '234', '-1', '0', '2', '0', '0', 'GRV 100');
INSERT INTO `staticveh` VALUES ('2', '567', '2468.62', '-1670.47', '13.2648', '11.2824', '234', '234', '-1', '0', '2', '0', '0', 'GRV 102');
INSERT INTO `staticveh` VALUES ('3', '567', '2319.34', '-1718.34', '13.4248', '179.711', '234', '234', '-1', '0', '2', '0', '0', 'GRV 108');
INSERT INTO `staticveh` VALUES ('4', '492', '2473.27', '-1691.92', '13.2328', '359.35', '234', '234', '-1', '0', '2', '0', '0', 'GRV 104');
INSERT INTO `staticveh` VALUES ('5', '492', '2478.07', '-1653.86', '13.175', '88.8351', '234', '234', '-1', '0', '2', '0', '0', 'GRV 101');
INSERT INTO `staticveh` VALUES ('6', '492', '2327.5', '-1677.39', '14.2472', '267.797', '234', '234', '-1', '0', '2', '0', '0', 'GRV 107');
INSERT INTO `staticveh` VALUES ('7', '412', '2505.74', '-1650.97', '13.5207', '114.071', '234', '234', '-1', '0', '2', '0', '0', 'GRV 105 ');
INSERT INTO `staticveh` VALUES ('8', '412', '2236.05', '-1638.63', '15.4109', '160.69', '234', '234', '-1', '0', '2', '0', '0', 'GRV 106');
INSERT INTO `staticveh` VALUES ('9', '412', '2509.33', '-1686.67', '13.3982', '47.0572', '234', '234', '-1', '0', '2', '0', '0', 'GRV 103');
INSERT INTO `staticveh` VALUES ('10', '517', '2044.71', '-1060.69', '24.9474', '156.373', '242', '242', '-1', '0', '3', '0', '0', 'GSW 126');
INSERT INTO `staticveh` VALUES ('11', '517', '1944.26', '-1130.96', '25.3566', '270.789', '242', '242', '-1', '0', '3', '0', '0', 'GSW 122');
INSERT INTO `staticveh` VALUES ('12', '517', '2011.73', '-1118.87', '26.1119', '134.176', '242', '242', '-1', '0', '3', '0', '0', 'GSW 125');
INSERT INTO `staticveh` VALUES ('13', '412', '1910.44', '-1117.7', '25.5632', '179.463', '242', '242', '-1', '0', '3', '0', '0', 'GSW 120');
INSERT INTO `staticveh` VALUES ('14', '412', '1987.51', '-1140.97', '25.5589', '89.6458', '242', '242', '-1', '0', '3', '0', '0', 'GSW 124');
INSERT INTO `staticveh` VALUES ('15', '412', '2090.95', '-1141.04', '25.4092', '89.2046', '242', '242', '-1', '0', '3', '0', '0', 'GSW 127');
INSERT INTO `staticveh` VALUES ('16', '566', '1934.66', '-1118.33', '26.204', '181.081', '242', '242', '-1', '0', '3', '0', '0', 'GSW 121');
INSERT INTO `staticveh` VALUES ('17', '566', '1957.21', '-1140.71', '25.5466', '269.203', '242', '242', '-1', '0', '3', '0', '0', 'GSW 123');
INSERT INTO `staticveh` VALUES ('18', '566', '2095.71', '-1278.95', '25.2743', '179.244', '242', '242', '-1', '0', '3', '0', '0', 'GSW 128');
INSERT INTO `staticveh` VALUES ('19', '466', '1888.04', '-2021.98', '13.203', '179.438', '135', '135', '-1', '0', '4', '0', '0', 'VNE 141');
INSERT INTO `staticveh` VALUES ('20', '466', '1901.86', '-2047.39', '13.2025', '89.6771', '135', '135', '-1', '0', '4', '0', '0', 'VNE 142');
INSERT INTO `staticveh` VALUES ('21', '466', '1842.78', '-2147.57', '13.2887', '214.703', '135', '135', '-1', '0', '4', '0', '0', 'VNE 146');
INSERT INTO `staticveh` VALUES ('22', '575', '1862.23', '-2057.56', '13.0627', '270.254', '135', '135', '-1', '0', '4', '0', '0', 'VNE 143');
INSERT INTO `staticveh` VALUES ('23', '575', '1947.34', '-2123.67', '13.1485', '269.734', '135', '135', '-1', '0', '4', '0', '0', 'VNE 147');
INSERT INTO `staticveh` VALUES ('24', '575', '1868.35', '-2007.53', '13.1493', '269.687', '135', '135', '-1', '0', '4', '0', '0', 'VNE 140');
INSERT INTO `staticveh` VALUES ('25', '474', '1931.67', '-1927.45', '13.2261', '272.433', '135', '135', '-1', '0', '4', '0', '0', 'VNE 148');
INSERT INTO `staticveh` VALUES ('26', '474', '1877.98', '-2026.39', '13.2249', '179.743', '135', '135', '-1', '0', '4', '0', '0', 'VNE 144');
INSERT INTO `staticveh` VALUES ('27', '474', '1869.74', '-2047.24', '13.2249', '271.599', '135', '135', '-1', '0', '4', '0', '0', 'VNE 145');
INSERT INTO `staticveh` VALUES ('28', '582', '759.966', '-1334.7', '13.5974', '180.295', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 203');
INSERT INTO `staticveh` VALUES ('29', '582', '782.864', '-1354.14', '13.5999', '89.6138', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 201');
INSERT INTO `staticveh` VALUES ('30', '582', '782.874', '-1358.89', '13.5981', '90.2786', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 200');
INSERT INTO `staticveh` VALUES ('31', '582', '764.486', '-1334.51', '13.5961', '181.326', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 204');
INSERT INTO `staticveh` VALUES ('32', '582', '755.488', '-1334.74', '13.5963', '180.942', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 202');
INSERT INTO `staticveh` VALUES ('33', '582', '768.954', '-1334.47', '13.5935', '180.54', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 205');
INSERT INTO `staticveh` VALUES ('34', '582', '737.72', '-1347.6', '13.5651', '271.013', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 206');
INSERT INTO `staticveh` VALUES ('35', '488', '741.951', '-1378.53', '25.8641', '267.97', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 207');
INSERT INTO `staticveh` VALUES ('36', '488', '742.141', '-1367.89', '25.873', '271.46', '1', '167', '-1', '0', '6', '0', '0', 'SA NET 208');
INSERT INTO `staticveh` VALUES ('37', '596', '1570.24', '-1710.06', '5.61163', '1.02222', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 250');
INSERT INTO `staticveh` VALUES ('38', '596', '1574.6', '-1709.91', '5.61194', '0.729281', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 251');
INSERT INTO `staticveh` VALUES ('39', '596', '1578.73', '-1709.88', '5.61101', '359.469', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 252');
INSERT INTO `staticveh` VALUES ('40', '596', '1583.31', '-1709.98', '5.612', '0.252567', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 253');
INSERT INTO `staticveh` VALUES ('41', '596', '1587.49', '-1709.94', '5.61191', '358.667', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 254');
INSERT INTO `staticveh` VALUES ('42', '599', '1585.87', '-1671.69', '5.61327', '270.375', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 255');
INSERT INTO `staticveh` VALUES ('43', '596', '1601.5', '-1687.95', '6.07956', '89.3154', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 256');
INSERT INTO `staticveh` VALUES ('44', '596', '1601.58', '-1683.89', '5.61156', '89.4662', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 257');
INSERT INTO `staticveh` VALUES ('45', '596', '1591.54', '-1709.82', '5.61215', '1.66497', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 258');
INSERT INTO `staticveh` VALUES ('46', '596', '1595.81', '-1709.99', '5.61131', '358.692', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 259');
INSERT INTO `staticveh` VALUES ('47', '599', '1558.77', '-1709.89', '5.61149', '359.136', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 260');
INSERT INTO `staticveh` VALUES ('48', '596', '1544.54', '-1655.04', '5.61072', '91.0683', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 261');
INSERT INTO `staticveh` VALUES ('49', '523', '1601.88', '-1710.18', '5.46109', '52.4577', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 262');
INSERT INTO `staticveh` VALUES ('50', '523', '1603.72', '-1708.93', '5.46176', '48.2699', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 263');
INSERT INTO `staticveh` VALUES ('51', '523', '1600.05', '-1711.36', '5.46053', '48.1778', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 264');
INSERT INTO `staticveh` VALUES ('52', '411', '1601.7', '-1700.29', '5.67217', '89.5488', '1', '2', '-1', '0', '1', '0', '3', 'LSPD 265');
INSERT INTO `staticveh` VALUES ('53', '599', '1529.1', '-1683.66', '5.61226', '270.293', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 266');
INSERT INTO `staticveh` VALUES ('54', '596', '1529.18', '-1688.24', '5.61147', '268.507', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 267');
INSERT INTO `staticveh` VALUES ('55', '525', '1545.1', '-1680.55', '5.76594', '90.3727', '0', '1', '-1', '0', '1', '0', '2', 'LSPD 268');
INSERT INTO `staticveh` VALUES ('56', '596', '1544.79', '-1658.88', '5.61255', '88.9312', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 269');
INSERT INTO `staticveh` VALUES ('57', '525', '1545.24', '-1684.98', '5.76969', '89.6124', '0', '1', '-1', '0', '1', '0', '2', 'LSPD 270');
INSERT INTO `staticveh` VALUES ('58', '427', '1530.43', '-1645.85', '6.02239', '180.237', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 271');
INSERT INTO `staticveh` VALUES ('59', '427', '1526.8', '-1646.06', '6.02251', '179.853', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 272');
INSERT INTO `staticveh` VALUES ('60', '523', '1558.51', '-1695.91', '5.46743', '271.748', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 273');
INSERT INTO `staticveh` VALUES ('61', '525', '1545.31', '-1676.29', '5.76247', '88.6402', '0', '1', '-1', '0', '1', '0', '2', 'LSPD 274');
INSERT INTO `staticveh` VALUES ('62', '523', '1558.52', '-1692.29', '5.46585', '269.203', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 275');
INSERT INTO `staticveh` VALUES ('63', '523', '1558.49', '-1694.05', '5.46664', '273.439', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 276');
INSERT INTO `staticveh` VALUES ('64', '411', '1534.64', '-1645.31', '5.6177', '180.552', '1', '1', '-1', '0', '1', '0', '3', 'LSPD 277');
INSERT INTO `staticveh` VALUES ('65', '411', '1544.98', '-1668.18', '5.76625', '89.1831', '1', '2', '-1', '0', '1', '0', '3', 'LSPD 278');
INSERT INTO `staticveh` VALUES ('66', '411', '1601.72', '-1696.04', '5.61771', '91.2461', '1', '1', '-1', '0', '1', '0', '3', 'LSPD 279');
INSERT INTO `staticveh` VALUES ('67', '416', '1111.02', '-1328.36', '13.452', '0.572554', '3', '1', '-1', '0', '7', '0', '0', 'LSES 300');
INSERT INTO `staticveh` VALUES ('68', '416', '1123.69', '-1327.91', '13.49', '2.19569', '3', '1', '-1', '0', '7', '0', '0', 'LSES 301');
INSERT INTO `staticveh` VALUES ('69', '416', '1097.82', '-1328.87', '13.4093', '359.937', '3', '1', '-1', '0', '7', '0', '0', 'LSES 302');
INSERT INTO `staticveh` VALUES ('70', '416', '1136.31', '-1309.95', '13.7315', '269.623', '3', '1', '-1', '0', '7', '0', '0', 'LSES 303');
INSERT INTO `staticveh` VALUES ('71', '416', '1136.21', '-1296.9', '13.7132', '271.623', '3', '1', '-1', '0', '7', '0', '0', 'LSES 304');
INSERT INTO `staticveh` VALUES ('72', '416', '1147.84', '-1346.88', '13.7963', '180.276', '3', '1', '-1', '0', '7', '0', '0', 'LSES 305');
INSERT INTO `staticveh` VALUES ('73', '599', '1135.88', '-1341.91', '13.9444', '359.316', '3', '1', '-1', '0', '7', '0', '0', 'LSES 306');
INSERT INTO `staticveh` VALUES ('74', '416', '1147.58', '-1313.75', '13.822', '359.517', '3', '1', '-1', '0', '7', '0', '0', 'LSES 307');
INSERT INTO `staticveh` VALUES ('75', '599', '1093.42', '-1313.88', '13.8735', '271.465', '3', '1', '-1', '0', '7', '0', '0', 'LSES 308');
INSERT INTO `staticveh` VALUES ('76', '416', '1177.72', '-1308.64', '14.0046', '269.79', '3', '1', '-1', '0', '7', '0', '0', 'LSES 309');
INSERT INTO `staticveh` VALUES ('77', '416', '1177.81', '-1338.84', '14.0475', '270.731', '3', '1', '-1', '0', '7', '0', '0', 'LSES 310');
INSERT INTO `staticveh` VALUES ('78', '416', '2005.38', '-1412.53', '17.1416', '178.49', '3', '1', '-1', '0', '7', '0', '0', 'LSES 311');
INSERT INTO `staticveh` VALUES ('79', '416', '2041.39', '-1427.21', '17.3136', '0.407467', '3', '1', '-1', '0', '7', '0', '0', 'LSES 312');
INSERT INTO `staticveh` VALUES ('80', '416', '2099.25', '-1447.73', '24.0242', '269.902', '3', '1', '-1', '0', '7', '0', '0', 'LSES 313');
INSERT INTO `staticveh` VALUES ('81', '416', '2000.47', '-1355.07', '23.949', '359.943', '3', '1', '-1', '0', '7', '0', '0', 'LSES 314');
INSERT INTO `staticveh` VALUES ('82', '599', '2035.27', '-1443.3', '17.554', '89.3114', '3', '1', '-1', '0', '7', '0', '0', 'LSES 315');
INSERT INTO `staticveh` VALUES ('83', '599', '2019.31', '-1411.06', '17.1809', '181.811', '3', '1', '-1', '0', '7', '0', '0', 'LSES 316');
INSERT INTO `staticveh` VALUES ('84', '405', '1665.02', '-1719.69', '20.3588', '358.743', '0', '0', '-1', '0', '5', '0', '0', 'GOV 350');
INSERT INTO `staticveh` VALUES ('85', '405', '1673.28', '-1719.84', '20.3621', '358.246', '0', '0', '-1', '0', '5', '0', '0', 'GOV 351');
INSERT INTO `staticveh` VALUES ('86', '405', '1656.17', '-1719.78', '20.3594', '358.15', '0', '0', '-1', '0', '5', '0', '0', 'GOV 352');
INSERT INTO `staticveh` VALUES ('87', '405', '1649.65', '-1719.57', '20.3558', '1.1354', '0', '0', '-1', '0', '5', '0', '0', 'GOV 353');
INSERT INTO `staticveh` VALUES ('88', '409', '1636.61', '-1685.35', '13.3294', '359.421', '1', '1', '-1', '0', '5', '0', '0', 'GOV 354');
INSERT INTO `staticveh` VALUES ('89', '426', '765.927', '-1381.05', '13.4045', '359.109', '167', '167', '-1', '0', '6', '0', '3', 'SA NET 209');
INSERT INTO `staticveh` VALUES ('90', '426', '761.883', '-1380.95', '13.3991', '1.06181', '167', '167', '-1', '0', '6', '0', '3', 'SA NET 210');
INSERT INTO `staticveh` VALUES ('91', '426', '769.998', '-1381.19', '13.4072', '357.729', '167', '167', '-1', '0', '6', '0', '3', 'SA NET 211');
INSERT INTO `staticveh` VALUES ('92', '555', '1361.23', '-1650.89', '13.0712', '272', '15', '15', '-1', '100', '0', '0', '0', 'EXAM 400');
INSERT INTO `staticveh` VALUES ('93', '555', '1361.2', '-1659.01', '13.074', '270.013', '15', '15', '-1', '100', '0', '0', '0', 'EXAM 401');
INSERT INTO `staticveh` VALUES ('94', '555', '1360.97', '-1643.4', '13.0996', '271.047', '15', '15', '-1', '100', '0', '0', '0', 'EXAM 402');
INSERT INTO `staticveh` VALUES ('95', '555', '1361.04', '-1635.44', '13.0889', '272.374', '15', '15', '-1', '100', '0', '0', '0', 'EXAM 403');
INSERT INTO `staticveh` VALUES ('96', '497', '1550.49', '-1707.52', '28.5757', '90.5438', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 280');
INSERT INTO `staticveh` VALUES ('97', '497', '1549.67', '-1643.77', '28.5759', '91.9345', '0', '1', '-1', '0', '1', '0', '0', 'LSPD 281');
INSERT INTO `staticveh` VALUES ('98', '563', '2027.42', '-1381.2', '49.0274', '128.519', '3', '1', '-1', '0', '7', '0', '0', 'LSES 317');
INSERT INTO `staticveh` VALUES ('99', '563', '2066.37', '-1427.61', '49.072', '126.516', '3', '1', '-1', '0', '7', '0', '0', 'LSES 318');
INSERT INTO `staticveh` VALUES ('100', '563', '1161.19', '-1364.35', '27.4434', '268.994', '3', '1', '-1', '0', '7', '0', '0', 'LSES 319');
INSERT INTO `staticveh` VALUES ('101', '563', '1162.87', '-1311.87', '32.1989', '267.033', '3', '1', '-1', '0', '7', '0', '0', 'LSES 320');
INSERT INTO `staticveh` VALUES ('102', '448', '2123.04', '-1789.13', '13.1533', '359.242', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 150');
INSERT INTO `staticveh` VALUES ('103', '448', '2115.71', '-1789.1', '13.1533', '0.100874', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 154');
INSERT INTO `staticveh` VALUES ('104', '448', '2121.31', '-1789.16', '13.1534', '1.8351', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 151');
INSERT INTO `staticveh` VALUES ('105', '448', '2117.56', '-1789.1', '13.1533', '359.598', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 153');
INSERT INTO `staticveh` VALUES ('106', '448', '2113.88', '-1789.06', '13.1574', '0.315901', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 155');
INSERT INTO `staticveh` VALUES ('107', '448', '2119.5', '-1789.16', '13.1548', '4.34474', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 152');
INSERT INTO `staticveh` VALUES ('108', '448', '2110.18', '-1788.98', '13.1577', '0.48052', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 157');
INSERT INTO `staticveh` VALUES ('109', '448', '2112', '-1789.05', '13.1564', '358.139', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 156');
INSERT INTO `staticveh` VALUES ('110', '448', '2108.29', '-1789', '13.159', '0.510157', '3', '3', '10', '0', '0', '1', '0', 'PIZZ 158');
INSERT INTO `staticveh` VALUES ('111', '574', '1642.8', '-1907.74', '13.2773', '19.2168', '1', '1', '10', '0', '0', '2', '0', 'SWP 111');
INSERT INTO `staticveh` VALUES ('112', '574', '1645.94', '-1906.92', '13.2773', '20.5804', '1', '1', '10', '0', '0', '2', '0', 'SWP 110');
INSERT INTO `staticveh` VALUES ('113', '574', '1639.8', '-1908.65', '13.2773', '17.3797', '1', '1', '10', '0', '0', '2', '0', 'SWP 112');
INSERT INTO `staticveh` VALUES ('114', '574', '1636.81', '-1909.48', '13.2773', '15.1209', '1', '1', '10', '0', '0', '2', '0', 'SWP 113');
INSERT INTO `staticveh` VALUES ('115', '574', '1633.63', '-1910.32', '13.2773', '14.5472', '1', '1', '10', '0', '0', '2', '0', 'SWP 114');
INSERT INTO `staticveh` VALUES ('116', '574', '1629.74', '-1902.18', '13.2787', '268.309', '1', '1', '10', '0', '0', '2', '0', 'SWP 116');
INSERT INTO `staticveh` VALUES ('117', '574', '1629.71', '-1906.42', '13.2768', '270.247', '1', '1', '10', '0', '0', '2', '0', 'SWP 115');
INSERT INTO `staticveh` VALUES ('118', '574', '1619.73', '-1896.33', '13.2749', '359.447', '1', '1', '10', '0', '0', '2', '0', 'SWP 118');
INSERT INTO `staticveh` VALUES ('119', '574', '1616.33', '-1896.31', '13.2741', '356.364', '1', '1', '10', '0', '0', '2', '0', 'SWP 119');
INSERT INTO `staticveh` VALUES ('120', '574', '1622.92', '-1896.37', '13.2757', '358.132', '1', '1', '10', '0', '0', '2', '0', 'SWP 117');
INSERT INTO `staticveh` VALUES ('121', '408', '2079.72', '-2033.29', '14.0957', '272.025', '1', '1', '10', '0', '0', '3', '0', 'GRB 126');
INSERT INTO `staticveh` VALUES ('122', '408', '2079.78', '-2028.31', '14.0989', '271.015', '1', '1', '10', '0', '0', '3', '0', 'GRB 125');
INSERT INTO `staticveh` VALUES ('123', '408', '2079.58', '-2017.71', '14.0967', '270.499', '1', '1', '10', '0', '0', '3', '0', 'GRB 123');
INSERT INTO `staticveh` VALUES ('124', '408', '2079.62', '-2023.11', '14.0974', '270.919', '1', '1', '10', '0', '0', '3', '0', 'GRB 124');
INSERT INTO `staticveh` VALUES ('125', '408', '2079.51', '-2007.21', '14.0971', '271.167', '1', '1', '10', '0', '0', '3', '0', 'GRB 121');
INSERT INTO `staticveh` VALUES ('126', '408', '2079.47', '-2001.85', '14.11', '271.408', '1', '1', '10', '0', '0', '3', '0', 'GRB 120');
INSERT INTO `staticveh` VALUES ('127', '531', '-1036.17', '-1175.83', '129.185', '91.3549', '128', '128', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('128', '531', '-1060.93', '-1133.77', '129.185', '267.178', '3', '3', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('129', '531', '-1036.25', '-1168.84', '129.182', '91.9193', '3', '3', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('130', '531', '-1109.64', '-1132.86', '129.183', '1.12067', '6', '6', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('131', '531', '-1036.24', '-1172.42', '129.184', '91.0645', '6', '6', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('132', '531', '-1061.18', '-1137.34', '129.182', '265.351', '6', '6', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('133', '531', '-1040.63', '-1069.39', '129.182', '179.146', '6', '6', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('134', '531', '-1061.19', '-1141.09', '129.185', '267.668', '128', '128', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('135', '531', '-1106.09', '-1132.8', '129.185', '2.06974', '128', '128', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('136', '531', '-1044.29', '-1069.34', '129.184', '179.876', '128', '128', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('137', '531', '-1037.18', '-1069.46', '129.185', '179.258', '3', '3', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('138', '531', '-1113.21', '-1132.95', '129.188', '1.11488', '3', '3', '10', '0', '0', '4', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('139', '408', '2079.52', '-2012.31', '14.1027', '270.603', '1', '1', '10', '0', '0', '3', '0', 'GRB 122');
INSERT INTO `staticveh` VALUES ('140', '593', '1719.83', '-2631.74', '13.5469', '0', '128', '1', '-1', '101', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('141', '593', '1706.58', '-2631.53', '13.5469', '0', '1', '1', '-1', '101', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('142', '593', '1688.74', '-2631.58', '14.0051', '358.352', '1', '1', '-1', '101', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('143', '593', '1672.22', '-2632.53', '13.5469', '0', '1', '1', '-1', '101', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('144', '593', '1653.94', '-2633.96', '13.5469', '0', '1', '1', '-1', '101', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('145', '473', '723.361', '-1503.2', '-0.445146', '180', '1', '1', '-1', '102', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('146', '473', '727.995', '-1503.21', '-0.431541', '180', '1', '1', '-1', '102', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('147', '473', '733.928', '-1505.32', '-0.380599', '180', '1', '1', '-1', '102', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('148', '473', '739.72', '-1505.35', '-0.619923', '180', '1', '1', '-1', '102', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('149', '473', '719.656', '-1504.16', '-0.513607', '180', '1', '1', '-1', '102', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('150', '610', '-1213.5', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('151', '610', '-1210.6', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('152', '610', '-1199.4', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('153', '610', '-1207.8', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('154', '610', '-1205', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('155', '610', '-1202.2', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('156', '610', '-1196.6', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('157', '610', '-1193.9', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('158', '610', '-1191.1', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('159', '610', '-1188.4', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('160', '610', '-1185.6', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('161', '610', '-1182.8', '-1124.1', '128.6', '0', '-1', '-1', '-1', '2', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('162', '403', '-59.3508', '-1112.06', '1.68428', '161.588', '1', '1', '10', '0', '0', '5', '0', 'TRK 104');
INSERT INTO `staticveh` VALUES ('163', '403', '-49.8198', '-1115.74', '1.68411', '160.231', '1', '1', '10', '0', '0', '5', '0', 'TRK 106');
INSERT INTO `staticveh` VALUES ('164', '403', '-68.759', '-1109', '1.68466', '161.206', '10', '10', '10', '0', '0', '5', '0', 'TRK 102');
INSERT INTO `staticveh` VALUES ('165', '403', '-76.854', '-1106.42', '1.685', '163.019', '32', '32', '10', '0', '0', '5', '0', 'TRK 100');
INSERT INTO `staticveh` VALUES ('166', '403', '-40.4077', '-1119.44', '1.68714', '158.556', '54', '54', '10', '0', '0', '5', '0', 'TRK 108');
INSERT INTO `staticveh` VALUES ('167', '403', '-73.1163', '-1107.72', '1.6841', '161.622', '98', '98', '10', '0', '0', '5', '0', 'TRK 101');
INSERT INTO `staticveh` VALUES ('168', '403', '-64.0175', '-1110.53', '1.68465', '160.978', '125', '125', '10', '0', '0', '5', '0', 'TRK 103');
INSERT INTO `staticveh` VALUES ('169', '403', '-44.8948', '-1117.59', '1.68436', '159.044', '125', '125', '10', '0', '0', '5', '0', 'TRK 107');
INSERT INTO `staticveh` VALUES ('170', '403', '-54.6164', '-1113.89', '1.68405', '159.92', '55', '55', '10', '0', '0', '5', '0', 'TRK 109');
INSERT INTO `staticveh` VALUES ('171', '403', '-35.6401', '-1120.93', '1.71424', '159.99', '55', '55', '10', '0', '0', '5', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('172', '435', '-43.4', '-1156.7', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('173', '435', '-42.2', '-1153.9', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('174', '435', '-39.8', '-1148.3', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('175', '435', '-41', '-1151.1', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('176', '435', '-38.6', '-1145.5', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('177', '435', '-37.4', '-1142.8', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('178', '435', '-36.2', '-1140.1', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('179', '435', '-35', '-1137.4', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('180', '435', '-33.8', '-1134.7', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('181', '435', '-32.6', '-1132', '1.7', '66', '245', '245', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('182', '431', '1935.84', '-1448.52', '13.5765', '270.411', '3', '3', '10', '0', '0', '6', '0', 'BUS 206');
INSERT INTO `staticveh` VALUES ('183', '431', '1920.57', '-1448.35', '13.5688', '270.436', '3', '3', '10', '0', '0', '6', '0', 'BUS 207');
INSERT INTO `staticveh` VALUES ('184', '431', '1968.93', '-1448.12', '13.5964', '90.2697', '3', '3', '10', '0', '0', '6', '0', 'BUS 208');
INSERT INTO `staticveh` VALUES ('185', '431', '1810.02', '-1395.23', '13.7646', '50.9367', '3', '3', '10', '0', '0', '6', '0', 'BUS 205');
INSERT INTO `staticveh` VALUES ('186', '431', '1870.49', '-1353.13', '13.5881', '270.643', '3', '3', '10', '0', '0', '6', '0', 'BUS 202');
INSERT INTO `staticveh` VALUES ('187', '431', '1864.72', '-1397.03', '13.5835', '359.948', '3', '3', '10', '0', '0', '6', '0', 'BUS 203');
INSERT INTO `staticveh` VALUES ('188', '431', '1902.96', '-1352.89', '13.5901', '89.9236', '3', '3', '10', '0', '0', '6', '0', 'BUS 200');
INSERT INTO `staticveh` VALUES ('189', '431', '1864.14', '-1364.33', '13.5893', '180.307', '3', '3', '10', '0', '0', '6', '0', 'BUS 204');
INSERT INTO `staticveh` VALUES ('190', '431', '1865.05', '-1410.17', '13.5988', '359.286', '3', '3', '10', '0', '0', '6', '0', 'BUS 201');
INSERT INTO `staticveh` VALUES ('191', '431', '1950.45', '-1447.82', '13.5951', '271.36', '3', '3', '10', '0', '0', '6', '0', 'BUS 210');
INSERT INTO `staticveh` VALUES ('192', '452', '718.977', '-1696.42', '-0.397386', '181.821', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('193', '452', '719.002', '-1633.05', '-0.680034', '180.045', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('194', '460', '716.378', '-1672.01', '1.69456', '225.363', '0', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('195', '473', '713.203', '-1643.51', '-0.144361', '264.776', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('196', '473', '714.236', '-1622.44', '-0.456596', '274.544', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('197', '473', '714.004', '-1688.25', '-0.314598', '275.246', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('198', '473', '714.407', '-1709.52', '-0.41082', '270.178', '1', '0', '-1', '0', '0', '0', '0', 'RNT 104');
INSERT INTO `staticveh` VALUES ('199', '401', '1078.09', '-1763.77', '13.0866', '90.3254', '70', '0', '-1', '0', '0', '0', '0', 'RNT 108');
INSERT INTO `staticveh` VALUES ('200', '527', '1083.83', '-1763.79', '13.1948', '270.408', '50', '0', '-1', '0', '0', '0', '0', 'RNT 109');
INSERT INTO `staticveh` VALUES ('201', '507', '1062.28', '-1754.98', '13.0174', '269.965', '91', '0', '-1', '0', '0', '0', '0', 'RNT 103');
INSERT INTO `staticveh` VALUES ('202', '585', '1084.23', '-1772.65', '13.1176', '270.075', '34', '0', '-1', '0', '0', '0', '0', 'RNT 101');
INSERT INTO `staticveh` VALUES ('203', '526', '1098.94', '-1757.89', '13.076', '89.8534', '23', '0', '-1', '0', '0', '0', '0', 'RNT 110');
INSERT INTO `staticveh` VALUES ('204', '546', '1078.03', '-1769.66', '13.1578', '90.0792', '77', '0', '-1', '0', '0', '0', '0', 'RNT 107');
INSERT INTO `staticveh` VALUES ('205', '551', '1062.13', '-1769.72', '13.2027', '270.014', '102', '0', '-1', '0', '0', '0', '0', 'RNT 105');
INSERT INTO `staticveh` VALUES ('206', '516', '1098.93', '-1754.85', '13.1206', '90.6382', '63', '0', '-1', '0', '0', '0', '0', 'RNT 100');
INSERT INTO `staticveh` VALUES ('207', '436', '1077.89', '-1760.78', '13.2405', '90.0713', '3', '0', '-1', '0', '0', '0', '0', 'RNT 111');
INSERT INTO `staticveh` VALUES ('208', '540', '1098.73', '-1766.73', '13.0902', '90.0727', '61', '0', '-1', '0', '0', '0', '0', 'RNT 102');
INSERT INTO `staticveh` VALUES ('209', '410', '1648.66', '-1136.66', '23.5614', '359.66', '55', '45', '-1', '0', '0', '0', '0', 'RNT 112');
INSERT INTO `staticveh` VALUES ('210', '513', '1459.7', '-2412', '14.103', '181.55', '1', '3', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('211', '487', '1477.86', '-2403.95', '13.7312', '178.385', '1', '3', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('212', '487', '1488.87', '-2404.35', '13.732', '177.724', '1', '3', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('213', '513', '1448.07', '-2412.59', '14.1053', '179.066', '1', '3', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('214', '593', '1503.02', '-2440.27', '14.0141', '91.0053', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('215', '593', '1503.05', '-2456.26', '14.014', '89.963', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('216', '553', '1540.51', '-2447.06', '14.8902', '243.674', '0', '3', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('217', '519', '1373.95', '-2455.5', '14.4764', '269.312', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('218', '519', '1374.48', '-2426.19', '14.4735', '270.199', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('219', '462', '1218.81', '-1826.64', '13.0108', '178.23', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('220', '462', '1217.6', '-1826.59', '13.009', '178.456', '3', '0', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('221', '522', '1214.69', '-1826.71', '12.9786', '181.385', '3', '0', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('222', '522', '1213.46', '-1826.72', '12.9785', '180.505', '0', '3', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('223', '461', '1209.14', '-1826.82', '12.9916', '178.641', '87', '87', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('224', '461', '1210.4', '-1826.86', '12.9919', '181.583', '78', '78', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('225', '468', '1205.94', '-1826.53', '13.0794', '179.423', '7', '7', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('226', '468', '1203.14', '-1826.45', '12.891', '179.658', '4', '2', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('227', '471', '1201.56', '-1826.45', '12.8919', '179.792', '38', '27', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('228', '481', '1196.82', '-1826.55', '12.9266', '181.009', '0', '0', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('229', '481', '1195.85', '-1826.66', '12.9002', '177.469', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('230', '510', '1198.45', '-1826.3', '13.0186', '179.688', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('231', '510', '1199.53', '-1826.31', '13.0186', '180.117', '3', '3', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('232', '510', '1424.3', '-1740.52', '13.1553', '3.84199', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('233', '510', '1425.37', '-1740.48', '13.155', '358.576', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('234', '510', '1429.17', '-1740.44', '13.1549', '-0', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('235', '510', '1427.77', '-1740.49', '13.1552', '357.609', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('236', '510', '1430.42', '-1740.4', '13.1551', '358.262', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('237', '510', '1434.97', '-1740.39', '13.155', '358.495', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('238', '510', '1436.52', '-1740.39', '13.155', '359.073', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('239', '510', '1433.34', '-1740.43', '13.1548', '354.937', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('240', '510', '1431.84', '-1740.43', '13.1548', '0.693537', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('241', '510', '1426.56', '-1740.44', '13.1551', '1.25916', '0', '0', '10', '15', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('242', '571', '2767.97', '-2439.48', '13.6484', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('243', '571', '2766.56', '-2440.08', '13.6484', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('244', '571', '2764.89', '-2440.52', '13.4818', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('245', '571', '2762.65', '-2440.11', '13.5047', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('246', '571', '2760.42', '-2439.96', '13.518', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('247', '571', '2758.33', '-2439.84', '13.4956', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('248', '571', '2755.9', '-2439.93', '13.6432', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('249', '571', '2756.04', '-2444.95', '13.6432', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('250', '571', '2758.69', '-2444.52', '13.5077', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('251', '571', '2760.7', '-2444.13', '13.5284', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('252', '571', '2762.72', '-2444.32', '13.517', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('253', '571', '2764.7', '-2444.53', '13.4962', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('254', '571', '2766.9', '-2445.19', '13.6432', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('255', '571', '2768.87', '-2444.74', '13.6432', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('256', '571', '2769', '-2450.74', '13.6432', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('257', '571', '2766.44', '-2450.74', '13.6432', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('258', '571', '2764.29', '-2450.68', '13.5088', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('259', '571', '2762.46', '-2451.2', '13.5349', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('260', '571', '2761.25', '-2450.09', '13.5455', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('261', '571', '2759.27', '-2451.04', '13.5282', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('262', '571', '2756.52', '-2450.93', '13.4688', '0', '1', '1', '-1', '10001', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('263', '494', '-1393.66', '-188.267', '1051.47', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('264', '494', '-1396.54', '-188.116', '1051.47', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('265', '494', '-1399.54', '-187.412', '1051.47', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('266', '494', '-1399.17', '-181.029', '1051.43', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('267', '494', '-1396.14', '-181.607', '1051.44', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('268', '494', '-1393.1', '-182.208', '1051.44', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('269', '494', '-1391.67', '-174.686', '1051.38', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('270', '494', '-1394.74', '-173.451', '1051.37', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('271', '494', '-1397.8', '-173.722', '1051.38', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('272', '494', '-1396.31', '-166.147', '1051.28', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('273', '494', '-1393.4', '-166.022', '1051.28', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('274', '494', '-1390.47', '-168.396', '1051.3', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('275', '494', '-1388.88', '-162.423', '1051.22', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('276', '494', '-1390.73', '-160.895', '1051.21', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('277', '494', '-1395.11', '-160.276', '1051.22', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('278', '513', '-1614.28', '-122.835', '14.144', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('279', '513', '-1619.99', '-124.123', '14.144', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('280', '513', '-1627.21', '-127.182', '14.144', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('281', '513', '-1637.44', '-130.087', '14.144', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('282', '513', '-1639.01', '-152.966', '14.1484', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('283', '513', '-1633.59', '-152.092', '14.1484', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('284', '513', '-1628.23', '-151.486', '14.144', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('285', '513', '-1623.73', '-150.835', '14.144', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('286', '513', '-1615.8', '-149.042', '14.1484', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('287', '513', '-1610', '-146.942', '14.3756', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('288', '513', '-1605.09', '-145.285', '14.5469', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('289', '513', '-1600.16', '-144.011', '14.5469', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('290', '513', '-1639.3', '-176.582', '14.3997', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('291', '513', '-1634.31', '-176.388', '14.5469', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('292', '513', '-1628.32', '-175.691', '14.5469', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('293', '513', '-1620.87', '-174.379', '14.5469', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');
INSERT INTO `staticveh` VALUES ('294', '513', '-1615.23', '-173.624', '14.5469', '0', '1', '1', '-1', '0', '0', '0', '0', 'NewCar');

-- ----------------------------
-- Table structure for `suggestions`
-- ----------------------------
DROP TABLE IF EXISTS `suggestions`;
CREATE TABLE `suggestions` (
  `ID` int(5) NOT NULL AUTO_INCREMENT,
  `Nickname` varchar(25) NOT NULL,
  `Level` int(2) NOT NULL,
  `Message` text NOT NULL,
  `Created` text NOT NULL,
  `Status` int(2) NOT NULL DEFAULT '0',
  `Title` varchar(25) NOT NULL,
  `Proof` text NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of suggestions
-- ----------------------------
INSERT INTO `suggestions` VALUES ('4', 'AldoKenzo', '3', 'Ai mancat un s la comanda /mycar din /carhelp... ', '23.06.2014 08:20', '1', 'Bug - /mycar', 'Am vorbit in joc!');
INSERT INTO `suggestions` VALUES ('5', 'Covrigel', '2', 'Am vazut ca: atunci cand un administrator activeaza evenimentul Counter-Strike scrie \r\n\"x activated an Counter-Strike event\", ceea ce e gresit, corect e a Counter-Strike event.', '23.06.2014 19:14', '1', 'Greseala gramaticala', 'Se poate verifica in script.');
INSERT INTO `suggestions` VALUES ('6', 'AldoKenzo', '3', 'Cand mor si ma spameaza la HQ ma spameaza in diverse locuri dar nu in fata HQ-ului.... ', '23.06.2014 22:33', '1', 'BUG - Varrio Nuevo Estrad', 'Stiu pe cineva care are o avut o problema la fel pe un server si a fost de vina interiorul.... incercati sa schimbati interiorul...');

-- ----------------------------
-- Table structure for `s_reply`
-- ----------------------------
DROP TABLE IF EXISTS `s_reply`;
CREATE TABLE `s_reply` (
  `ID` int(5) NOT NULL AUTO_INCREMENT,
  `c_id` int(5) NOT NULL,
  `Nickname` varchar(25) NOT NULL,
  `Message` text NOT NULL,
  `Action` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM AUTO_INCREMENT=40 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of s_reply
-- ----------------------------

-- ----------------------------
-- Table structure for `turfs`
-- ----------------------------
DROP TABLE IF EXISTS `turfs`;
CREATE TABLE `turfs` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Owned` int(2) NOT NULL,
  `Time` int(3) NOT NULL,
  `MinX` varchar(16) NOT NULL,
  `MinY` varchar(16) NOT NULL,
  `MaxX` varchar(16) NOT NULL,
  `MaxY` varchar(16) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of turfs
-- ----------------------------
INSERT INTO `turfs` VALUES ('1', '3', '0', '576.773', '-668.117', '862.459', '-423.292');
INSERT INTO `turfs` VALUES ('2', '3', '0', '105.734', '-302.494', '384.989', '89.379');
INSERT INTO `turfs` VALUES ('3', '3', '0', '-206.002', '-157.242', '45.767', '151.028');
INSERT INTO `turfs` VALUES ('4', '3', '0', '1142.497', '115.417', '1425.985', '487.093');
INSERT INTO `turfs` VALUES ('5', '4', '0', '2134.280', '-137.217', '2582.050', '213.053');

-- ----------------------------
-- Table structure for `users`
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL,
  `Password` varchar(150) NOT NULL,
  `Level` int(4) NOT NULL DEFAULT '1',
  `Cash` int(10) NOT NULL DEFAULT '100',
  `Admin` int(3) NOT NULL DEFAULT '0',
  `Banned` int(2) NOT NULL DEFAULT '0',
  `Muted` int(2) NOT NULL DEFAULT '0',
  `MutedTime` int(2) NOT NULL DEFAULT '0',
  `CarLic` int(2) NOT NULL DEFAULT '0',
  `FlyLic` int(2) NOT NULL DEFAULT '0',
  `BoatLic` int(2) NOT NULL DEFAULT '0',
  `FishLic` int(2) NOT NULL DEFAULT '0',
  `GunLic` int(2) NOT NULL DEFAULT '0',
  `MatsLic` int(2) NOT NULL DEFAULT '0',
  `Warns` int(2) NOT NULL DEFAULT '0',
  `Job` int(2) NOT NULL DEFAULT '0',
  `Jailed` int(2) NOT NULL DEFAULT '0',
  `JailTime` int(2) NOT NULL DEFAULT '0',
  `Wanted` int(2) NOT NULL DEFAULT '0',
  `Leader` int(3) NOT NULL DEFAULT '0',
  `Member` int(3) NOT NULL DEFAULT '0',
  `SpawnChange` int(2) NOT NULL DEFAULT '0',
  `Rank` int(2) NOT NULL DEFAULT '0',
  `FacWarns` int(2) NOT NULL DEFAULT '0',
  `Chara` int(2) NOT NULL DEFAULT '47',
  `Drugs` int(2) NOT NULL DEFAULT '0',
  `Materials` int(2) NOT NULL DEFAULT '0',
  `Exp` int(11) NOT NULL DEFAULT '1',
  `FPunish` int(2) NOT NULL DEFAULT '0',
  `Bizkey` int(2) NOT NULL DEFAULT '-1',
  `WantedLevel` int(2) NOT NULL DEFAULT '0',
  `LastCrime` char(50) NOT NULL DEFAULT 'None',
  `LastReporter` char(25) NOT NULL DEFAULT 'None',
  `LastDate` char(50) NOT NULL DEFAULT 'None',
  `Crimes` int(4) NOT NULL DEFAULT '0',
  `Arrests` int(4) NOT NULL DEFAULT '0',
  `TrackLose` int(2) NOT NULL,
  `TotalXP` int(11) NOT NULL DEFAULT '1',
  `LastLogin` varchar(50) NOT NULL DEFAULT 'Nonee',
  `RegisterDate` varchar(50) NOT NULL DEFAULT 'Nonee',
  `online` int(2) NOT NULL DEFAULT '0',
  `ipCountry` varchar(30) NOT NULL,
  `ipCity` varchar(30) NOT NULL,
  `ipISP` varchar(30) NOT NULL,
  `Helper` int(2) NOT NULL DEFAULT '0',
  `JobTime` int(2) NOT NULL DEFAULT '0',
  `PhoneNr` int(8) NOT NULL DEFAULT '0',
  `Fuel` int(3) NOT NULL DEFAULT '0',
  `Bank` int(3) NOT NULL DEFAULT '0',
  `WDeaths` int(3) NOT NULL DEFAULT '0',
  `HouseKey` int(3) NOT NULL DEFAULT '-1',
  `FormatNr` varchar(30) NOT NULL DEFAULT '000-0000',
  `Tutorial` int(3) NOT NULL DEFAULT '0',
  `Email` varchar(50) NOT NULL DEFAULT 'default@host.domain',
  `CarKey1` int(2) NOT NULL DEFAULT '0',
  `CarKey2` int(2) NOT NULL DEFAULT '0',
  `CarKey3` int(2) NOT NULL DEFAULT '0',
  `CarKey4` int(2) NOT NULL DEFAULT '0',
  `CarKey5` int(2) NOT NULL DEFAULT '0',
  `PIN` int(5) NOT NULL DEFAULT '0',
  `OnExp` int(2) NOT NULL DEFAULT '0',
  `KeyReset` int(2) NOT NULL DEFAULT '0',
  `ConfirmKey` varchar(150) NOT NULL DEFAULT 'None',
  `Emailed` int(2) NOT NULL DEFAULT '0',
  `Activated` int(2) NOT NULL DEFAULT '0',
  `PremiumAcc` int(2) NOT NULL DEFAULT '0',
  `Refferal` int(2) NOT NULL,
  `TRefferals` int(2) NOT NULL DEFAULT '0',
  `TMoney` int(2) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3144 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES ('2298', 'Maurice', 'FFDB76AF72C89D7FACD59B3A8C31444BDD154E37509FE51C646D5478D7006E6D39813D8A821731662C9C39CF712E98C532402FD0C726E413EB5E4E7BE692FE5A', '4', '57107', '6', '0', '0', '0', '270', '0', '0', '0', '0', '0', '0', '5', '0', '0', '0', '1', '0', '0', '8', '0', '265', '0', '0', '144', '0', '4', '0', 'atac cop', 'SebyCr7', '23.06.2014 20:47:34', '24', '0', '0', '444', '02.06.2015 08:54', '21.06.2014 10:09', '0', 'Unknown', 'Unknown', 'Unknown', '0', '189', '2574598', '0', '28037', '0', '2', '257-4598', '1', 'matragunamihai97@gmail.com', '8', '0', '0', '0', '0', '1590', '58', '0', 'None', '0', '1', '1', '0', '1', '0');
