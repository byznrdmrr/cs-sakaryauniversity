
---------------functions---------------------
-----
--1--
-----
Create function fncKdvHesabi(@fiyat money)
returns money
as 
begin
declare @kdv money
set @kdv =@fiyat*0.18
return @kdv 
end
-----------------------------------------------------------------------
Select TOPLAMTUTAR, dbo.fncKdvHesabi (7) as KDV from hesapOdemeleri

-----
--2--
-----

Create function bosMasa(@bosM bit)
returns table
as
return select * from masalar where DURUM=@bosM
go
---------------------------------------------------
Select * from dbo.bosMasa (1)


------
--3--
------

Create function fncSatisSayisi(@toplam int)
returns int
as
begin
declare @sayi int
set @sayi=+@toplam
return @sayi
end
----------------------------------------------------------
Select ADET, dbo.fncSatisSayisi(3 ) as TOPLAM  from satislar

------
--4---
------


Create function fncGenelKdvliFiyat
(@fiyat money, @adet int, @indirim float)
returns money
as 
begin
 declare @kdvli money
	set @kdvli=@fiyat*@adet
	set @kdvli=@kdvli+(@kdvli*0.18)
	set @kdvli=@kdvli*(1-@indirim)
	return @kdvli
end
-----------------------------------------------------
Select TOPLAMTUTAR, dbo. as KDVliFiyat from hesapOdemeleri

-------
---5---
-------

Create function izinliPersonel(@izin bit)
returns table
as
return select * from personeller where DURUM=@izin
go
------------------------------------------------
Select *from dbo.izinliPersonel(0)

---------------TRÝGGER-----------------------------

go
Create trigger personelSil
on personeller 
instead of 
delete
as
declare @id int

select @id=ID from deleted
set @id=(select ID from deleted)
update personeller set DURUM=1 where ID=@id
-------------------------------
select * from personeller

delete personeller where ID=2

---------------------------------------------------

Select * from personeller where  DURUM=0
