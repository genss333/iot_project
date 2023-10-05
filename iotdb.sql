-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 05, 2023 at 10:45 AM
-- Server version: 11.1.0-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `iotdb`
--

-- --------------------------------------------------------

--
-- Table structure for table `tbdevices`
--

CREATE TABLE `tbdevices` (
  `id` varchar(20) NOT NULL,
  `status` varchar(10) NOT NULL,
  `detail` varchar(20) NOT NULL,
  `close_date_time` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tbdevices`
--

INSERT INTO `tbdevices` (`id`, `status`, `detail`, `close_date_time`) VALUES
('D1', 'OFF', 'หลอดไฟในบ้าน1', ''),
('D2', 'OFF', 'หลอดไฟหน้าบ้าน', '2023-10-05T16:42');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tbdevices`
--
ALTER TABLE `tbdevices`
  ADD PRIMARY KEY (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
