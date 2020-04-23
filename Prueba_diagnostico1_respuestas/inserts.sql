INSERT INTO `teachers` (`idteachers`,`first_name`,`last_name`,`email`,`brithdate`) VALUES (1,'Pedro','Pedro','pedro@gmail.com','2008-7-04');
INSERT INTO `teachers` (`idteachers`,`first_name`,`last_name`,`email`,`brithdate`) VALUES (2,'Juan','Juan','juan@gmail.com','2008-7-04');
INSERT INTO `teachers` (`idteachers`,`first_name`,`last_name`,`email`,`brithdate`) VALUES (3,'Diego','Diego','diego@gmail.com','2008-7-04');

INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (1,'a','a','a@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (2,'b','b','b@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (3,'c','c','c@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (4,'d','d','d@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (5,'e','e','e@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (6,'f','f','f@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (7,'g','g','g@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (8,'h','h','h@gmail.com','2008-7-04');
INSERT INTO `students` (`idstudents`,`first_name`,`last_name`,`email`,`birthdate`) VALUES (9,'i','i','i@gmail.com','2008-7-04');

INSERT INTO `courses` (`idcourses`,`teacher_fk`,`code`,`name`,`start_date`,`end_date`) VALUES (1,1,'123','A','2008-7-04','2008-7-04');
INSERT INTO `courses` (`idcourses`,`teacher_fk`,`code`,`name`,`start_date`,`end_date`) VALUES (2,2,'3423','B','2008-7-04','2008-7-04');
INSERT INTO `courses` (`idcourses`,`teacher_fk`,`code`,`name`,`start_date`,`end_date`) VALUES (3,3,'1234','C','2008-7-04','2008-7-04');

INSERT INTO `exams` (`idexams`,`course_fk`,`exam_date`,`name`) VALUES (1,1,'2008-7-04','muerte');
INSERT INTO `exams` (`idexams`,`course_fk`,`exam_date`,`name`) VALUES (2,2,'2008-7-04','desesperacion');
INSERT INTO `exams` (`idexams`,`course_fk`,`exam_date`,`name`) VALUES (3,3,'2008-7-04','destruccion');

INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (1,'1',1,1);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (2,'1',1,2);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (3,'23',1,3);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (4,'2',2,4);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (5,'4',2,5);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (6,'5',2,6);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (7,'6',3,7);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (8,'712',3,8);
INSERT INTO `evaluations` (`idevaluations`,`score`,`exam_fk`,`student_fk`) VALUES (9,'3',3,9);

