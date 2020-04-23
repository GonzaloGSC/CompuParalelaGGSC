select a.name,year(start_date),avg(score),std(score),min(score),max(score) from courses a
inner join exams as b on a.idcourses = b.course_fk
inner join evaluations as c on b.idexams = c.exam_fk
group by name;


