-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 21, 2023 at 04:36 PM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bhcms`
--

-- --------------------------------------------------------

--
-- Table structure for table `allergy`
--

CREATE TABLE `allergy` (
  `allergy_id` int(10) NOT NULL,
  `allergy_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `allergy`
--

INSERT INTO `allergy` (`allergy_id`, `allergy_name`) VALUES
(1, 'Pollen'),
(2, 'Dust'),
(3, 'Pet dander'),
(4, 'Mold'),
(5, 'Food'),
(6, 'Insect bites'),
(7, 'Medication'),
(8, 'Latex'),
(9, 'Cosmetics'),
(10, 'Chemicals'),
(11, 'Grass'),
(12, 'Tree nuts'),
(13, 'Shellfish'),
(14, 'Milk'),
(15, 'Eggs'),
(16, 'Wheat'),
(17, 'Soy'),
(18, 'Fish'),
(19, 'Peanuts'),
(20, 'Sesame');

-- --------------------------------------------------------

--
-- Table structure for table `diagnosisreport`
--

CREATE TABLE `diagnosisreport` (
  `diagnosis_id` int(10) NOT NULL,
  `checkup_id` int(10) NOT NULL,
  `treatment` text NOT NULL,
  `description` text NOT NULL,
  `diagnosis_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `diagnosisreport`
--

INSERT INTO `diagnosisreport` (`diagnosis_id`, `checkup_id`, `treatment`, `description`, `diagnosis_name`) VALUES
(1, 2, 'Prescription medication', 'Patient diagnosed with common cold. Advised to rest and take medication as prescribed.', 'Common Cold'),
(2, 16, 'Physical therapy', 'Patient diagnosed with back pain. Recommended physical therapy exercises.', 'Injury'),
(3, 17, 'Antibiotics', 'Patient diagnosed with bacterial infection. Prescribed antibiotics for treatment.', 'Infection'),
(4, 7, 'Painkillers', 'Patient diagnosed with migraine. Prescribed painkillers for relief.', 'Common Cold'),
(5, 9, 'Lifestyle changes', 'Patient diagnosed with high blood pressure. Advised to make lifestyle changes and monitor blood pressure regularly.', 'Hypertension'),
(6, 15, 'Antihistamines', 'Patient diagnosed with allergies. Prescribed antihistamines for symptom relief.', 'Allergy'),
(7, 13, 'Surgical intervention', 'Patient diagnosed with appendicitis. Urgent surgical intervention recommended.', 'Appendicitis'),
(8, 19, 'Physical therapy', 'Patient diagnosed with sports injury. Recommended physical therapy sessions.', 'Injury'),
(9, 17, 'Dietary changes', 'Patient diagnosed with diabetes. Advised to make dietary changes and monitor blood sugar levels.', 'Diabetes'),
(10, 19, 'Prescription medication', 'Patient diagnosed with respiratory infection. Prescribed medication for treatment.', 'Infection'),
(11, 24, 'Antibiotics', 'Patient diagnosed with strep throat. Prescribed antibiotics for treatment.', 'Influenza'),
(12, 4, 'Painkillers', 'Patient diagnosed with headache. Prescribed painkillers for relief.', 'Influenza'),
(13, 31, 'Physical therapy', 'Patient diagnosed with muscle strain. Recommended physical therapy sessions.', 'Influenza'),
(14, 8, 'Prescription medication', 'Patient diagnosed with sinusitis. Prescribed medication for treatment.', 'Sinusitis'),
(15, 23, 'Lifestyle changes', 'Patient diagnosed with high cholesterol. Advised to make lifestyle changes and monitor cholesterol levels.', 'Hypertension'),
(16, 12, 'Antihistamines', 'Patient diagnosed with hay fever. Prescribed antihistamines for symptom relief.', 'Allergy'),
(17, 27, 'Surgical intervention', 'Patient diagnosed with cataracts. Recommended surgical intervention.', 'Cataract'),
(18, 42, 'Physical therapy', 'Patient diagnosed with joint pain. Recommended physical therapy sessions.', 'Injury'),
(19, 32, 'Dietary changes', 'Patient diagnosed with food intolerance. Advised to make dietary changes.', 'Diarrhea'),
(20, 20, 'Prescription medication', 'Patient diagnosed with urinary tract infection. Prescribed medication for treatment.', 'Infection');

-- --------------------------------------------------------

--
-- Table structure for table `dosage`
--

CREATE TABLE `dosage` (
  `med_id` int(10) NOT NULL,
  `dosage` float(4,1) NOT NULL,
  `weight_range` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `dosage`
--

INSERT INTO `dosage` (`med_id`, `dosage`, `weight_range`) VALUES
(1, 2.5, '50-59 kg'),
(1, 2.0, '40-49 kg'),
(1, 1.5, '30-39 kg'),
(2, 1.0, '50-59 kg'),
(2, 0.8, '40-49 kg'),
(2, 0.6, '30-39 kg'),
(3, 0.5, '50-59 kg'),
(3, 0.4, '40-49 kg'),
(3, 0.3, '30-39 kg'),
(4, 2.5, '50-59 kg'),
(4, 2.0, '40-49 kg'),
(4, 1.5, '30-39 kg'),
(5, 1.0, '50-59 kg'),
(5, 0.8, '40-49 kg'),
(5, 0.6, '30-39 kg'),
(6, 0.5, '50-59 kg'),
(6, 0.4, '40-49 kg'),
(6, 0.3, '30-39 kg'),
(7, 2.5, '50-59 kg'),
(7, 2.0, '40-49 kg'),
(7, 1.5, '30-39 kg'),
(8, 1.0, '50-59 kg'),
(8, 0.8, '40-49 kg'),
(8, 0.6, '30-39 kg'),
(9, 0.5, '50-59 kg'),
(9, 0.4, '40-49 kg'),
(9, 0.3, '30-39 kg'),
(10, 2.5, '50-59 kg'),
(10, 2.0, '40-49 kg'),
(10, 1.5, '30-39 kg'),
(11, 1.0, '50-59 kg'),
(11, 0.8, '40-49 kg'),
(11, 0.6, '30-39 kg'),
(12, 0.5, '50-59 kg'),
(12, 0.4, '40-49 kg'),
(12, 0.3, '30-39 kg'),
(13, 2.5, '50-59 kg'),
(13, 2.0, '40-49 kg'),
(13, 1.5, '30-39 kg'),
(14, 1.0, '50-59 kg'),
(14, 0.8, '40-49 kg'),
(14, 0.6, '30-39 kg'),
(15, 0.5, '50-59 kg'),
(15, 0.4, '40-49 kg'),
(15, 0.3, '30-39 kg'),
(16, 2.5, '50-59 kg'),
(16, 2.0, '40-49 kg'),
(16, 1.5, '30-39 kg'),
(17, 1.0, '50-59 kg'),
(17, 0.8, '40-49 kg'),
(17, 0.6, '30-39 kg'),
(18, 0.5, '50-59 kg'),
(18, 0.4, '40-49 kg'),
(18, 0.3, '30-39 kg'),
(20, 1.5, '50-59 kg'),
(20, 1.0, '40-49 kg'),
(20, 0.5, '30-39 kg');

-- --------------------------------------------------------

--
-- Table structure for table `healthworker`
--

CREATE TABLE `healthworker` (
  `hw_id` int(10) NOT NULL,
  `fname` varchar(30) NOT NULL,
  `mname` varchar(30) NOT NULL,
  `lname` varchar(30) NOT NULL,
  `birth_date` date NOT NULL,
  `gender` varchar(1) NOT NULL,
  `position` varchar(50) NOT NULL,
  `stat` varchar(1) DEFAULT 'Y'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `healthworker`
--

INSERT INTO `healthworker` (`hw_id`, `fname`, `mname`, `lname`, `birth_date`, `gender`, `position`, `stat`) VALUES
(1, 'Maria', 'Tan', 'Galacio', '1987-12-02', 'F', 'midwife', 'N'),
(2, 'Reymart', 'Galdo', 'Ramirez', '1995-01-23', 'M', 'Barangay Health Nurse', 'Y'),
(3, 'Michael', 'Colas', 'Jamaica', '1988-12-03', 'M', 'Midwife', 'Y'),
(4, 'Sarah', 'Dalen', 'Geronimo', '1992-06-08', 'F', 'Barangay Nutrition Scholar', 'Y'),
(5, 'Robert', 'Enghog', 'Brown', '1991-02-12', 'M', 'Medical Technologist', 'Y'),
(6, 'Emily', 'Felimon', 'Dart', '1994-08-17', 'F', 'Midwife', 'Y'),
(7, 'Daniel', 'Galolo', 'Padilla', '1987-11-29', 'M', 'Barangay Health Worker', 'Y'),
(8, 'Olivia', 'Hedal', 'Anderson', '1993-03-04', 'F', 'Barangay Health Nurse', 'Y'),
(9, 'James', 'Ingkog', 'Wilo', '1990-07-22', 'M', 'Midwife', 'Y'),
(10, 'Sophia', 'Jaso', 'Amil', '1989-01-18', 'F', 'Barangay Nutrition Scholar', 'Y'),
(11, 'Lindsay', 'Petal', 'Doblas', '2002-09-01', 'F', 'Barangay Health Nurse', 'Y');

-- --------------------------------------------------------

--
-- Table structure for table `hwcontact`
--

CREATE TABLE `hwcontact` (
  `hw_id` int(10) DEFAULT NULL,
  `contact_no` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `hwcontact`
--

INSERT INTO `hwcontact` (`hw_id`, `contact_no`) VALUES
(1, '09123456789'),
(1, '09123456789'),
(2, '09234233518'),
(3, '09463458634'),
(4, '09439587434'),
(5, '09864353454'),
(6, '09333333333'),
(6, '09435245434'),
(7, '04593252454'),
(8, '09542352435'),
(9, '42545623455'),
(10, '0945325423'),
(10, '09111111111');

-- --------------------------------------------------------

--
-- Table structure for table `medicalhistory`
--

CREATE TABLE `medicalhistory` (
  `checkup_id` int(10) NOT NULL,
  `res_id` int(10) NOT NULL,
  `checkup_date` date NOT NULL,
  `doctor_fname` varchar(30) NOT NULL,
  `doctor_mi` varchar(1) NOT NULL,
  `doctor_lname` varchar(30) NOT NULL,
  `temp` float(4,2) DEFAULT NULL,
  `bp` float(4,2) DEFAULT NULL,
  `height` float(4,1) DEFAULT NULL,
  `weight` float(4,1) DEFAULT NULL,
  `reason` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `medicalhistory`
--

INSERT INTO `medicalhistory` (`checkup_id`, `res_id`, `checkup_date`, `doctor_fname`, `doctor_mi`, `doctor_lname`, `temp`, `bp`, `height`, `weight`, `reason`) VALUES
(1, 1, '2022-01-01', 'John', 'A', 'Mactan', 98.60, 1.50, 165.5, 70.2, 'Annual checkup'),
(2, 2, '2022-01-02', 'John', 'A', 'Mactan', 99.00, 1.44, 170.2, 68.5, 'Fever and cough'),
(3, 3, '2022-01-03', 'John', 'A', 'Mactan', 97.90, 1.57, 160.0, 75.0, 'Routine examination'),
(4, 4, '2022-01-04', 'John', 'A', 'Mactan', 98.80, 1.56, 155.8, 65.7, 'School purposes checkup'),
(5, 5, '2022-01-05', 'John', 'A', 'Mactan', 99.50, 1.47, 175.0, 80.1, 'Allergy symptoms'),
(6, 6, '2022-01-06', 'John', 'A', 'Mactan', 98.70, 1.57, 168.9, 62.3, 'Stomachache'),
(7, 7, '2022-01-07', 'Daniel', 'G', 'Davis', 99.20, 1.56, 162.3, 72.9, 'Headache'),
(8, 8, '2022-01-08', 'Olivia', 'H', 'Mahumas', 98.90, 1.51, 167.6, 70.5, 'Annual checkup'),
(9, 9, '2022-01-09', 'John', 'A', 'Mactan', 99.10, 1.51, 171.2, 74.8, 'Chest pain'),
(10, 10, '2022-01-10', 'John', 'A', 'Mactan', 98.50, 1.60, 160.5, 68.0, 'Fever and sore throat'),
(11, 1, '2022-01-11', 'John', 'A', 'Mactan', 98.40, 1.55, 165.3, 71.0, 'Follow-up visit'),
(12, 1, '2022-01-12', 'Olivia', 'H', 'Mahumas', 98.90, 1.50, 164.9, 69.5, 'Flu symptoms'),
(13, 3, '2022-01-13', 'Olivia', 'H', 'Mahumas', 98.60, 1.53, 159.7, 73.2, 'Routine examination'),
(14, 3, '2022-01-14', 'Daniel', 'G', 'Davis', 98.30, 1.56, 161.0, 72.5, 'Follow-up visit'),
(15, 11, '2022-01-15', 'Robert', 'K', 'Anderson', 98.80, 1.56, 168.0, 75.5, 'Allergy symptoms'),
(16, 12, '2022-01-16', 'Ava', 'L', 'Wilson', 99.30, 1.53, 172.5, 72.1, 'Back pain'),
(17, 13, '2022-01-17', 'James', 'M', 'Martinez', 98.70, 1.50, 166.8, 68.9, 'Annual checkup'),
(18, 14, '2022-01-18', 'Mia', 'N', 'Garcia', 98.50, 1.55, 165.2, 70.4, 'Fever and cough'),
(19, 15, '2022-01-19', 'Daniel', 'G', 'Davis', 99.20, 1.51, 170.7, 74.7, 'School purposes checkup'),
(20, 16, '2022-01-20', 'Daniel', 'G', 'Davis', 98.90, 1.53, 161.9, 73.8, 'Stomachache'),
(21, 17, '2022-01-21', 'John', 'A', 'Mactan', 99.00, 1.50, 166.5, 69.3, 'Headache'),
(22, 18, '2022-01-22', 'Olivia', 'H', 'Mahumas', 98.60, 1.56, 165.7, 71.8, 'Annual checkup'),
(23, 19, '2022-01-23', 'Daniel', 'G', 'Davis', 98.30, 1.55, 168.2, 74.2, 'Chest pain'),
(24, 20, '2022-01-24', 'Daniel', 'G', 'Davis', 99.10, 1.53, 173.4, 72.6, 'Fever and sore throat'),
(25, 20, '2022-01-25', 'Olivia', 'H', 'Mahumas', 98.70, 1.51, 174.1, 73.9, 'Follow-up visit'),
(26, 6, '2022-02-01', 'John', 'A', 'Mactan', 98.50, 1.50, 169.1, 63.2, 'Follow-up visit'),
(27, 12, '2022-02-02', 'John', 'A', 'Mactan', 98.90, 1.55, 171.3, 71.5, 'Annual checkup'),
(28, 17, '2022-02-03', 'John', 'A', 'Mactan', 99.30, 1.56, 167.8, 70.1, 'Follow-up visit'),
(29, 4, '2022-02-04', 'John', 'A', 'Mactan', 98.60, 1.56, 156.5, 66.2, 'Headache'),
(30, 8, '2022-02-05', 'John', 'A', 'Mactan', 99.10, 1.51, 168.9, 71.8, 'Follow-up visit'),
(31, 13, '2022-02-06', 'John', 'A', 'Mactan', 98.80, 1.50, 165.2, 69.4, 'Routine examination'),
(32, 1, '2022-02-07', 'John', 'A', 'Mactan', 98.70, 1.55, 164.9, 70.3, 'Stomachache'),
(33, 9, '2022-02-08', 'John', 'A', 'Mactan', 98.30, 1.53, 170.2, 75.1, 'Cough and colds'),
(34, 5, '2022-02-09', 'John', 'A', 'Mactan', 99.20, 1.47, 175.5, 80.5, 'Annual checkup'),
(35, 15, '2022-02-10', 'Jacob', 'O', 'Rodriguez', 98.90, 1.53, 161.4, 69.8, 'Follow-up visit'),
(36, 3, '2022-02-11', 'John', 'A', 'Mactan', 98.40, 1.56, 160.8, 73.0, 'Follow-up visit'),
(37, 14, '2022-02-12', 'Mia', 'N', 'Garcia', 99.00, 1.50, 165.0, 70.7, 'Fever and cough'),
(38, 19, '2022-02-13', 'Mia', 'N', 'Garcia', 98.70, 1.56, 167.5, 74.0, 'Headache'),
(39, 7, '2022-02-14', 'Mia', 'N', 'Garcia', 98.60, 1.56, 163.7, 68.5, 'Annual checkup'),
(40, 11, '2022-02-15', 'Mia', 'N', 'Garcia', 99.30, 1.53, 170.9, 72.3, 'Stomachache'),
(41, 2, '2022-02-16', 'Mia', 'N', 'Garcia', 98.80, 1.51, 172.3, 75.6, 'Cough and colds'),
(42, 16, '2022-02-17', 'Mia', 'N', 'Garcia', 98.50, 1.55, 165.7, 71.9, 'Routine examination'),
(43, 10, '2022-02-18', 'Mia', 'N', 'Garcia', 99.10, 1.53, 173.2, 73.2, 'Follow-up visit'),
(44, 20, '2022-02-19', 'Mia', 'N', 'Garcia', 98.90, 1.51, 174.9, 73.5, 'Follow-up visit'),
(45, 6, '2022-02-20', 'Mia', 'N', 'Garcia', 99.00, 1.50, 169.8, 65.9, 'Annual checkup'),
(46, 12, '2022-02-21', 'Mia', 'N', 'Garcia', 98.60, 1.56, 171.0, 70.4, 'Fever and cough'),
(47, 17, '2022-02-22', 'Mia', 'N', 'Garcia', 99.30, 1.55, 167.3, 68.7, 'Headache'),
(48, 4, '2022-02-23', 'Mia', 'N', 'Garcia', 98.70, 1.50, 157.2, 67.6, 'Annual checkup'),
(49, 8, '2022-02-24', 'Mia', 'N', 'Garcia', 99.20, 1.56, 169.6, 70.9, 'Follow-up visit');

-- --------------------------------------------------------

--
-- Table structure for table `medicine`
--

CREATE TABLE `medicine` (
  `med_id` int(10) NOT NULL,
  `name` varchar(50) NOT NULL,
  `brand` varchar(50) NOT NULL,
  `type` varchar(50) NOT NULL,
  `exp_date` date NOT NULL,
  `description` text NOT NULL,
  `strength` int(11) NOT NULL,
  `manufacturer` varchar(50) NOT NULL,
  `qty` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `medicine`
--

INSERT INTO `medicine` (`med_id`, `name`, `brand`, `type`, `exp_date`, `description`, `strength`, `manufacturer`, `qty`) VALUES
(1, 'Paracetamol', 'Panadol', 'Tablet', '2023-12-31', 'Fever and pain relief', 500, 'Johnson & Johnson', 100),
(2, 'Amoxicillin', 'Amoxil', 'Capsule', '2024-06-30', 'Antibiotic', 250, 'Pfizer', 100),
(3, 'Loratadine', 'Claritin', 'Tablet', '2022-02-19', 'Antihistamine', 10, 'Bayer', 80),
(4, 'Omeprazole', 'Prilosec', 'Capsule', '2024-02-28', 'Acid reflux relief', 20, 'AstraZeneca', 30),
(5, 'Cetirizine', 'Zyrtec', 'Tablet', '2023-10-31', 'Antihistamine', 5, 'GlaxoSmithKline', 60),
(6, 'Simvastatin', 'Zocor', 'Tablet', '2024-04-30', 'Cholesterol-lowering', 40, 'Merck', 25),
(7, 'Metformin', 'Glucophage', 'Tablet', '2024-01-31', 'Antidiabetic', 500, 'Novartis', 40),
(8, 'Aspirin', 'Bayer', 'Tablet', '2023-09-30', 'Pain reliever', 325, 'Bayer', 200),
(9, 'Ibuprofen', 'Advil', 'Tablet', '2024-03-31', 'Pain and inflammation relief', 200, 'Pfizer', 150),
(10, 'Acetaminophen', 'Tylenol', 'Tablet', '2023-11-30', 'Pain and fever reducer', 325, 'Johnson & Johnson', 100),
(11, 'Ciprofloxacin', 'Cipro', 'Tablet', '2024-05-31', 'Antibiotic', 500, 'Bayer', 30),
(12, 'Atorvastatin', 'Lipitor', 'Tablet', '2024-03-31', 'Cholesterol-lowering', 80, 'Pfizer', 20),
(13, 'Metoprolol', 'Lopressor', 'Tablet', '2023-10-31', 'Beta blocker', 50, 'Novartis', 40),
(14, 'Amlodipine', 'Norvasc', 'Tablet', '2024-01-31', 'Antihypertensive', 5, 'Pfizer', 60),
(15, 'Fluoxetine', 'Prozac', 'Capsule', '2023-08-31', 'Antidepressant', 20, 'Eli Lilly', 30),
(16, 'Albuterol', 'Proventil', 'Inhaler', '2024-06-30', 'Bronchodilator', 90, 'GlaxoSmithKline', 10),
(17, 'Lisinopril', 'Prinivil', 'Tablet', '2024-02-28', 'Antihypertensive', 10, 'Merck', 50),
(18, 'Levothyroxine', 'Synthroid', 'Tablet', '2023-12-31', 'Thyroid hormone replacement', 100, 'AbbVie', 20),
(20, 'Warfarin', 'Coumadin', 'Tablet', '2023-09-30', 'Anticoagulant', 5, 'Bristol-Myers Squibb', 30);

-- --------------------------------------------------------

--
-- Table structure for table `prescription`
--

CREATE TABLE `prescription` (
  `pres_id` int(10) NOT NULL,
  `checkup_id` int(10) NOT NULL,
  `med_id` int(10) NOT NULL,
  `qty` int(11) DEFAULT 0,
  `volume` float(3,1) DEFAULT 0.0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `prescription`
--

INSERT INTO `prescription` (`pres_id`, `checkup_id`, `med_id`, `qty`, `volume`) VALUES
(1, 1, 1, 3, 30.0),
(2, 1, 3, 2, 15.5),
(3, 2, 2, 1, 10.0),
(4, 3, 5, 4, 40.0),
(5, 3, 6, 2, 20.0),
(6, 4, 9, 1, 5.0),
(7, 4, 8, 3, 30.0),
(8, 5, 7, 2, 20.0),
(9, 5, 10, 1, 10.0),
(10, 6, 12, 4, 40.0),
(11, 6, 15, 2, 20.0),
(12, 7, 11, 1, 5.0),
(13, 7, 13, 3, 30.0),
(14, 8, 14, 2, 20.0),
(15, 8, 17, 1, 10.0),
(17, 9, 16, 2, 20.0),
(18, 10, 18, 1, 5.0),
(19, 10, 20, 3, 30.0),
(20, 11, 2, 2, 20.0);

-- --------------------------------------------------------

--
-- Table structure for table `rescontact`
--

CREATE TABLE `rescontact` (
  `res_id` int(10) NOT NULL,
  `contact_no` varchar(15) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `rescontact`
--

INSERT INTO `rescontact` (`res_id`, `contact_no`) VALUES
(1, '09876543210'),
(2, '09234567890'),
(3, '09345678901'),
(4, '09456789012'),
(5, '09123456789'),
(6, '09678901234'),
(7, '09789012345'),
(8, '09890123456'),
(9, '09901234567'),
(10, '09111223344'),
(11, '09222333445'),
(12, '09333444556'),
(13, '09444555667'),
(14, '09555666778'),
(15, '09666777889'),
(16, '09777888990'),
(17, '09888999001'),
(18, '09999000112'),
(19, '09123456789'),
(20, '09234567890'),
(1, '09876543210'),
(5, '09456789023'),
(7, '09567890134'),
(4, '09678901245'),
(10, '09890123467'),
(13, '09901234578'),
(19, '09111223355'),
(23, '09222333466'),
(21, '09333444577'),
(5, '09876542343');

-- --------------------------------------------------------

--
-- Table structure for table `resident`
--

CREATE TABLE `resident` (
  `res_id` int(10) NOT NULL,
  `fname` varchar(30) NOT NULL,
  `mname` varchar(30) NOT NULL,
  `lname` varchar(30) NOT NULL,
  `birth_date` date NOT NULL,
  `gender` varchar(1) NOT NULL,
  `street` varchar(50) NOT NULL,
  `barangay` varchar(50) DEFAULT 'Dao',
  `municipality` varchar(50) DEFAULT 'Tagbilaran',
  `province` varchar(50) DEFAULT 'Bohol',
  `bloodtype` varchar(5) DEFAULT NULL,
  `death_date` date DEFAULT NULL,
  `hw_id` int(10) NOT NULL,
  `stat` varchar(1) DEFAULT 'Y'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `resident`
--

INSERT INTO `resident` (`res_id`, `fname`, `mname`, `lname`, `birth_date`, `gender`, `street`, `barangay`, `municipality`, `province`, `bloodtype`, `death_date`, `hw_id`, `stat`) VALUES
(1, 'John', 'Alexander', 'Smith', '1990-05-15', 'M', 'Main Street', 'Dao', 'Tagbilaran', 'Bohol', 'O+', '2023-03-21', 1, 'N'),
(2, 'Jane', 'Elizabeth', 'Doe', '1985-09-20', 'F', 'Park Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'A-', NULL, 2, 'Y'),
(3, 'Michael', 'Christopher', 'Johnson', '1988-12-03', 'M', 'Sunset Boulevard', 'Dao', 'Tagbilaran', 'Bohol', 'B+', NULL, 3, 'Y'),
(4, 'Sarah', 'Isabella', 'Williams', '1992-06-08', 'F', 'Beach Road', 'Dao', 'Tagbilaran', 'Bohol', 'AB-', NULL, 4, 'Y'),
(5, 'Robert', 'William', 'Brown', '1991-02-12', 'M', 'Ocean Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'A+', NULL, 5, 'Y'),
(6, 'Emily', 'Grace', 'Davis', '1994-08-17', 'F', 'Mountain View', 'Dao', 'Tagbilaran', 'Bohol', 'O-', NULL, 6, 'Y'),
(7, 'Daniel', 'James', 'Taylor', '1987-11-29', 'M', 'Riverside Drive', 'Dao', 'Tagbilaran', 'Bohol', 'B-', NULL, 7, 'Y'),
(8, 'Olivia', 'Sophia', 'Anderson', '1993-03-04', 'F', 'Garden Lane', 'Dao', 'Tagbilaran', 'Bohol', 'O+', NULL, 8, 'Y'),
(9, 'James', 'Alexander', 'Wilson', '1990-07-22', 'M', 'Hillside Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'AB+', NULL, 9, 'Y'),
(10, 'Sophia', 'Isabella', 'Miller', '1989-01-18', 'F', 'Valley Road', 'Dao', 'Tagbilaran', 'Bohol', 'A-', NULL, 10, 'Y'),
(11, 'Benjamin', 'Joseph', 'Lee', '1995-04-06', 'M', 'Maple Street', 'Dao', 'Tagbilaran', 'Bohol', 'O-', NULL, 1, 'Y'),
(12, 'Ava', 'Elizabeth', 'Clark', '1992-09-10', 'F', 'Cedar Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'B+', NULL, 2, 'Y'),
(13, 'Logan', 'Christopher', 'Rodriguez', '1986-12-11', 'M', 'Pine Lane', 'Dao', 'Tagbilaran', 'Bohol', 'AB-', NULL, 3, 'Y'),
(14, 'Mia', 'Grace', 'Hernandez', '1993-02-25', 'F', 'Willow Court', 'Dao', 'Tagbilaran', 'Bohol', 'A+', NULL, 4, 'Y'),
(15, 'Lucas', 'William', 'Garcia', '1991-06-28', 'M', 'Spruce Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'O-', NULL, 5, 'Y'),
(16, 'Emma', 'Sophia', 'Lopez', '1994-05-03', 'F', 'Cherry Street', 'Dao', 'Tagbilaran', 'Bohol', 'B-', NULL, 6, 'Y'),
(17, 'Noah', 'Alexander', 'Morales', '1987-08-19', 'M', 'Oak Drive', 'Dao', 'Tagbilaran', 'Bohol', 'O+', NULL, 7, 'Y'),
(18, 'Isabella', 'Emma', 'Cruz', '1993-01-12', 'F', 'Elm Road', 'Dao', 'Tagbilaran', 'Bohol', 'AB+', NULL, 8, 'Y'),
(19, 'Ethan', 'Joseph', 'Rivera', '1990-04-26', 'M', 'Birch Lane', 'Dao', 'Tagbilaran', 'Bohol', 'A-', NULL, 9, 'Y'),
(20, 'Oliver', 'Michael', 'Gonzalez', '1989-07-09', 'M', 'Cypress Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'O-', NULL, 10, 'Y'),
(21, 'Liam', 'Daniel', 'Martinez', '1988-11-01', 'M', 'Palm Street', 'Dao', 'Tagbilaran', 'Bohol', 'B+', '2023-03-12', 1, 'Y'),
(22, 'Sophie', 'Olivia', 'Sanchez', '1992-07-09', 'F', 'Grove Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'O-', '2022-09-28', 2, 'Y'),
(23, 'Henry', 'Joseph', 'Lopez', '1993-04-15', 'M', 'Spruce Lane', 'Dao', 'Tagbilaran', 'Bohol', 'A+', '2023-01-06', 3, 'Y'),
(24, 'Chloe', 'Grace', 'Torres', '1991-09-27', 'F', 'Cedar Road', 'Dao', 'Tagbilaran', 'Bohol', 'AB-', '2022-12-19', 4, 'Y'),
(25, 'William', 'Benjamin', 'Garcia', '1990-06-14', 'M', 'Pine Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'O+', '2023-05-05', 5, 'Y'),
(26, 'Sofia', 'Isabella', 'Reyes', '1995-02-25', 'F', 'Willow Street', 'Dao', 'Tagbilaran', 'Bohol', 'B-', '2022-11-17', 6, 'Y'),
(27, 'Daniel', 'Jacob', 'Morales', '1987-12-05', 'M', 'Oak Lane', 'Dao', 'Tagbilaran', 'Bohol', 'A-', '2023-02-10', 7, 'Y'),
(28, 'Aria', 'Elizabeth', 'Cruz', '1994-03-18', 'F', 'Elm Drive', 'Dao', 'Tagbilaran', 'Bohol', 'O+', '2022-10-31', 8, 'Y'),
(29, 'Logan', 'Michael', 'Rivera', '1993-08-22', 'M', 'Birch Avenue', 'Dao', 'Tagbilaran', 'Bohol', 'AB+', '2023-04-07', 9, 'Y'),
(30, 'Olivia', 'Charlotte', 'Gonzalez', '1989-11-11', 'F', 'Cypress Lane', 'Dao', 'Tagbilaran', 'Bohol', 'O-', '2022-07-24', 10, 'Y'),
(31, 'Rezelle June', 'Galolo', 'Udtohan', '2003-06-22', 'F', 'Purok 5', 'Dao', 'Tagbilaran', 'Bohol', NULL, NULL, 4, 'Y'),
(32, 'Magalano', 'Galiton', 'Salas', '1923-03-27', 'M', 'Wanstreet', 'Dao', 'Tagbilaran', 'Bohol', NULL, '2023-01-30', 8, 'Y'),
(33, 'Magalano', 'Galiton', 'Salas', '1923-03-27', 'M', 'Wanstreet', 'Dao', 'Tagbilaran', 'Bohol', NULL, '2023-01-27', 10, 'Y'),
(34, 'Samshey', 'Galdo', 'Salisay', '1925-03-27', 'F', 'Wanstreet', 'Dao', 'Tagbilaran', 'Bohol', 'A+', '2023-03-04', 1, 'Y'),
(35, 'Malikoy', 'Opac', 'Salamander', '1998-03-27', 'M', 'Wanstreet', 'Dao', 'Tagbilaran', 'Bohol', NULL, '2023-02-27', 5, 'Y'),
(36, 'Lora', 'Kanti', 'Ganzon', '1943-03-27', 'F', 'Wanstreet', 'Dao', 'Tagbilaran', 'Bohol', 'OA', '2023-01-27', 9, 'Y'),
(37, 'Maine', 'Hakdog', 'Mendoza', '1978-03-27', 'F', 'Wanstreet', 'Dao', 'Tagbilaran', 'Bohol', 'A+', '2023-04-21', 10, 'Y');

-- --------------------------------------------------------

--
-- Table structure for table `resident_allergy`
--

CREATE TABLE `resident_allergy` (
  `id_no` int(10) NOT NULL,
  `res_id` int(10) NOT NULL,
  `allergy_id` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `resident_allergy`
--

INSERT INTO `resident_allergy` (`id_no`, `res_id`, `allergy_id`) VALUES
(1, 1, 1),
(2, 1, 2),
(3, 2, 3),
(4, 2, 4),
(5, 3, 5),
(6, 3, 5),
(7, 4, 6),
(8, 4, 7),
(9, 5, 8),
(10, 5, 9),
(11, 6, 10),
(12, 6, 10),
(13, 7, 11),
(14, 7, 12),
(15, 8, 13),
(16, 8, 14),
(17, 9, 15),
(18, 9, 15),
(19, 10, 16),
(20, 10, 17),
(21, 1, 18),
(22, 2, 19),
(23, 3, 20),
(24, 4, 20),
(25, 5, 20);

-- --------------------------------------------------------

--
-- Table structure for table `vaccinationrecord`
--

CREATE TABLE `vaccinationrecord` (
  `vax_id` int(10) NOT NULL,
  `checkup_id` int(10) NOT NULL,
  `vax_date` date NOT NULL,
  `barangay` varchar(50) DEFAULT 'Dao',
  `municipality` varchar(50) DEFAULT 'Tagbilaran',
  `province` varchar(50) DEFAULT 'Bohol',
  `dose_no` int(11) NOT NULL,
  `vax_type` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `vaccinationrecord`
--

INSERT INTO `vaccinationrecord` (`vax_id`, `checkup_id`, `vax_date`, `barangay`, `municipality`, `province`, `dose_no`, `vax_type`) VALUES
(1, 1, '2022-01-05', 'Dao', 'Tagbilaran', 'Bohol', 1, 'COVID-19'),
(2, 4, '2022-02-10', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Influenza'),
(3, 5, '2022-03-15', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Polio'),
(4, 14, '2022-04-20', 'Dao', 'Tagbilaran', 'Bohol', 3, 'Hepatitis B'),
(5, 17, '2022-05-25', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Measles'),
(6, 11, '2022-06-30', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Pneumococcal'),
(7, 13, '2022-08-05', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Diphtheria'),
(8, 25, '2022-09-10', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Tetanus'),
(9, 18, '2022-10-15', 'Dao', 'Tagbilaran', 'Bohol', 1, 'COVID-19'),
(10, 19, '2022-11-20', 'Dao', 'Tagbilaran', 'Bohol', 3, 'Influenza'),
(11, 2, '2022-01-10', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Polio'),
(12, 4, '2022-02-15', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Hepatitis B'),
(13, 26, '2022-03-20', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Measles'),
(14, 48, '2022-04-25', 'Dao', 'Tagbilaran', 'Bohol', 3, 'Pneumococcal'),
(15, 27, '2022-05-30', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Diphtheria'),
(16, 34, '2022-07-05', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Tetanus'),
(17, 33, '2022-08-10', 'Dao', 'Tagbilaran', 'Bohol', 1, 'COVID-19'),
(18, 25, '2022-09-15', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Influenza'),
(19, 36, '2022-10-20', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Polio'),
(20, 20, '2022-11-25', 'Dao', 'Tagbilaran', 'Bohol', 3, 'Hepatitis B'),
(21, 1, '2022-01-05', 'Dao', 'Tagbilaran', 'Bohol', 1, 'COVID-19'),
(22, 3, '2022-02-10', 'Dao', 'Tagbilaran', 'Bohol', 2, 'Influenza'),
(23, 5, '2022-03-15', 'Dao', 'Tagbilaran', 'Bohol', 1, 'Polio'),
(24, 7, '2022-04-20', 'Dao', 'Tagbilaran', 'Bohol', 3, 'Hepatitis B');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `allergy`
--
ALTER TABLE `allergy`
  ADD PRIMARY KEY (`allergy_id`);

--
-- Indexes for table `diagnosisreport`
--
ALTER TABLE `diagnosisreport`
  ADD PRIMARY KEY (`diagnosis_id`),
  ADD KEY `fk_diagnosis_checkup` (`checkup_id`);

--
-- Indexes for table `dosage`
--
ALTER TABLE `dosage`
  ADD KEY `fk_med_dosage` (`med_id`);

--
-- Indexes for table `healthworker`
--
ALTER TABLE `healthworker`
  ADD PRIMARY KEY (`hw_id`);

--
-- Indexes for table `hwcontact`
--
ALTER TABLE `hwcontact`
  ADD KEY `fk_hwcontact` (`hw_id`);

--
-- Indexes for table `medicalhistory`
--
ALTER TABLE `medicalhistory`
  ADD PRIMARY KEY (`checkup_id`),
  ADD KEY `fk_med_res` (`res_id`);

--
-- Indexes for table `medicine`
--
ALTER TABLE `medicine`
  ADD PRIMARY KEY (`med_id`);

--
-- Indexes for table `prescription`
--
ALTER TABLE `prescription`
  ADD PRIMARY KEY (`pres_id`),
  ADD KEY `fk_pres_checkup` (`checkup_id`),
  ADD KEY `fk_pres_med` (`med_id`);

--
-- Indexes for table `rescontact`
--
ALTER TABLE `rescontact`
  ADD KEY `fk_rescontact` (`res_id`);

--
-- Indexes for table `resident`
--
ALTER TABLE `resident`
  ADD PRIMARY KEY (`res_id`),
  ADD KEY `fk_hw_res` (`hw_id`);

--
-- Indexes for table `resident_allergy`
--
ALTER TABLE `resident_allergy`
  ADD PRIMARY KEY (`id_no`),
  ADD KEY `fk_resid` (`res_id`),
  ADD KEY `fk_allergyid` (`allergy_id`);

--
-- Indexes for table `vaccinationrecord`
--
ALTER TABLE `vaccinationrecord`
  ADD PRIMARY KEY (`vax_id`),
  ADD KEY `fk_vax_checkup` (`checkup_id`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `diagnosisreport`
--
ALTER TABLE `diagnosisreport`
  ADD CONSTRAINT `fk_diagnosis_checkup` FOREIGN KEY (`checkup_id`) REFERENCES `medicalhistory` (`checkup_id`) ON DELETE CASCADE;

--
-- Constraints for table `dosage`
--
ALTER TABLE `dosage`
  ADD CONSTRAINT `fk_med_dosage` FOREIGN KEY (`med_id`) REFERENCES `medicine` (`med_id`) ON DELETE CASCADE;

--
-- Constraints for table `hwcontact`
--
ALTER TABLE `hwcontact`
  ADD CONSTRAINT `fk_hwcontact` FOREIGN KEY (`hw_id`) REFERENCES `healthworker` (`hw_id`) ON DELETE CASCADE;

--
-- Constraints for table `medicalhistory`
--
ALTER TABLE `medicalhistory`
  ADD CONSTRAINT `fk_med_res` FOREIGN KEY (`res_id`) REFERENCES `resident` (`res_id`) ON DELETE CASCADE;

--
-- Constraints for table `prescription`
--
ALTER TABLE `prescription`
  ADD CONSTRAINT `fk_pres_checkup` FOREIGN KEY (`checkup_id`) REFERENCES `medicalhistory` (`checkup_id`) ON DELETE CASCADE,
  ADD CONSTRAINT `fk_pres_med` FOREIGN KEY (`med_id`) REFERENCES `medicine` (`med_id`) ON DELETE CASCADE;

--
-- Constraints for table `rescontact`
--
ALTER TABLE `rescontact`
  ADD CONSTRAINT `fk_rescontact` FOREIGN KEY (`res_id`) REFERENCES `resident` (`res_id`) ON DELETE CASCADE;

--
-- Constraints for table `resident`
--
ALTER TABLE `resident`
  ADD CONSTRAINT `fk_hw_res` FOREIGN KEY (`hw_id`) REFERENCES `healthworker` (`hw_id`);

--
-- Constraints for table `resident_allergy`
--
ALTER TABLE `resident_allergy`
  ADD CONSTRAINT `fk_allergyid` FOREIGN KEY (`allergy_id`) REFERENCES `allergy` (`allergy_id`),
  ADD CONSTRAINT `fk_resid` FOREIGN KEY (`res_id`) REFERENCES `resident` (`res_id`) ON DELETE CASCADE;

--
-- Constraints for table `vaccinationrecord`
--
ALTER TABLE `vaccinationrecord`
  ADD CONSTRAINT `fk_vax_checkup` FOREIGN KEY (`checkup_id`) REFERENCES `medicalhistory` (`checkup_id`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
