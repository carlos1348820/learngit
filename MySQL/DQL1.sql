#进阶1：基础查询
/*
语法：
select 查询列表 from 表名；
特点：
1.查询列表可以是：表中的字段，常量值，表达式，函数
2.查询的结果是一个虚拟的表格
*/

USE myemployees;

#1.查询表中的单个字段
SELECT last_name FROM employees;

#2.查询表中的多个字段
SELECT last_name,salary,email FROM employees;

#3.查询表中所有字段
  #方式一：
SELECT 
  `employee_id`,
  `first_name`,
  `last_name`,
  `email`,
  `phone_number`,
  `job_id`,
  `salary`,
  `commission_pct`,
  `manager_id`,
  `department_id`,
  `hiredate` 
FROM
  employees ;
  #方式2：
SELECT * FROM employees;

#4.查询常量值
SELECT 100;
SELECT 'john';

#5.查询表达式
SELECT 100%98;

#6.查询函数
SELECT VERSION();

#7.起别名  : 便于理解；可以区分查询结果；别名中不能有特殊符号，需加双引号
  # 方式1
SELECT 100%98 AS 结果;
SELECT last_name AS 姓,first_name AS 名 FROM employees;
  #方式2
SELECT last_name 姓,first_name 名 FROM employees;

#8.去重
SELECT DISTINCT department_id FROM employees;

#9.+号作用:只有运算符功能(会将字符型数值转换成数值型，转换失败返回0） 100+90=190；‘100’+90=190   ‘a'+90=90  null+90=null
 #连接员工姓名为一个字段，并显示姓名
SELECT 
  CONCAT(last_name," ",first_name," ",IFNULL(commission_pct,0)) AS 姓名 
FROM
  employees ;

