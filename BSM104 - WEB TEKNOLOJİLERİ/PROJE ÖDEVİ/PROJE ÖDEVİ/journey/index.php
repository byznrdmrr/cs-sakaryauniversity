<!DOCTYPE html>
<?php include("kontrol/veritabani.php") ?>
<html lang="en">
		 <head>
		 <title>Anasayfa - karasu.com</title>
		 <meta charset="utf-8">
		 <link rel="icon" href="images/favicon.ico">
		 <link rel="shortcut icon" href="images/favicon.ico" />
		 <link rel="stylesheet" href="css/style.css">
		 <link rel="stylesheet" href="css/slider.css">
		 <script src="js/jquery.js"></script>
		 <script src="js/jquery-migrate-1.1.1.js"></script>
		 <script src="js/superfish.js"></script>
		 <script src="js/sForm.js"></script>
		 <script src="js/jquery.jqtransform.js"></script>
		 <script src="js/jquery.equalheights.js"></script>
		 <script src="js/jquery.easing.1.3.js"></script>
		 <script src="js/tms-0.4.1.js"></script>
		<script src="js/jquery-ui-1.10.3.custom.min.js"></script>
		 <script src="js/jquery.ui.totop.js"></script>
		
		 <script>
			$(window).load(function(){
			$('.slider')._TMS({
							show:0,
							pauseOnHover:false,
							prevBu:'.prev',
							nextBu:'.next',
							playBu:false,
							duration:800,
							preset:'random', 
							pagination:false,//'.pagination',true,'<ul></ul>'
							pagNums:false,
							slideshow:8000,
							numStatus:false,
							banners:true,
					waitBannerAnimation:false,
				progressBar:false
			})	;
			 $( "#tabs" ).tabs();
		 
		$().UItoTop({ easingType: 'easeOutQuart' });
			});
			
			
			
		 </script>
		 <!--[if lt IE 8]>
			 <div style=' clear: both; text-align:center; position: relative;'>
				 <a href="http://windows.microsoft.com/en-US/internet-explorer/products/ie/home?ocid=ie6_countdown_bannercode">
					 <img src="http://storage.ie6countdown.com/assets/100/images/banners/warning_bar_0000_us.jpg" border="0" height="42" width="820" alt="You are using an outdated browser. For a faster, safer browsing experience, upgrade for free today." />
				 </a>
			</div>
		<![endif]-->
		<!--[if lt IE 9]>
			<script src="js/html5shiv.js"></script>
			<link rel="stylesheet" media="screen" href="css/ie.css">

		<![endif]-->
		 </head>
		 <body class="page1">
<!--==============================header=================================-->
 <header> 
	<div class="container_12">
		<div class="grid_12"> 
		<h1><a href="index.php"><img src="images/logo.png" alt="Gerald Harris attorney at law"></a> </h1>
					
				 
					 <div class="clear"></div>
			</div>
					<div class="menu_block">
					 <nav	class="" >
						<ul class="sf-menu">
									 <li class="current"><a href="index.php">Ana Sayfa</a></li>
									 <li><a href="hakkimizda.html">Hakkımızda</a></li>
									 <li><a href="galeri.html">Galeri</a></li>
									 <li><a href="turmerkezleri.html">Turlar</a></li>
									 <li><a href="giris.html">Kullanıcı Girisi</a></li>
									 <li><a href="iletisim.html">ıletisim</a></li>
								 </ul>
							</nav>
					 <div class="clear"></div>
					 </div>
					 <div class="clear"></div>
	</div>
</header>

<div class="main">
	<div class="container_12">
		<div class="grid_12">
	 <div class="slider-relative">
			<div class="slider-block">
				<div class="slider">
					<a href="#" class="prev"></a><a href="#" class="next"></a>
					<ul class="items">
						<li><img src="images/slide.jpg" alt="">
								<div class="banner">
									
									<span> görülmeye değer </span>
								</div>
						</li>
						<li><img src="images/slide1.jpg" alt=""></li>
						<li><img src="images/slide2.jpg" alt=""></li>
						<li><img src="images/slide3.jpg" alt=""></li>
					</ul>
				</div>
			</div>
		</div>
	</div></div>
	
<!--=======content================================-->

<div class="content">
	<div class="container_12">
		<div class="grid_12">
			<h3>İçerikler</h3>
		</div>
		<div class="boxes">
		<div class="grid_4">
					<figure>
						<div><img src="images/page1_img1.jpg" alt=""></div>
						<figcaption>
							<h3>Hakkımızda</h3>
							İnsan, yaşamına derin çizgilerin nerede atılacağını bilseydi; oralara ilk gidişini, 
							o kentlerle ilk karşılaştığı anı asla unutmazdı... Karasu'da bu duyguyu hissedecek ve yaşayacaksınız...
							<a href="" class="btn">Detaylar</a>
						</figcaption>
					</figure>
				</div>
				<div class="grid_4">
					<figure>
						<div><img src="images/page1_img2.jpg" alt=""></div>
						<figcaption>
							<h3>Turlarımız</h3>
							<ul>
								<li>♦Acarlar Longoz Gölü</li>
								<li>♦Küçük Boğaz Lagün Gölü</li>
								<li>♦Maden Deresi</li>
								<li>♦Yeni Mahalle</li>
							</ul>
							<a href="" class="btn">Detaylar</a>

						</figcaption>
					</figure>
				</div>
				<div class="grid_4">
					<figure>
						<div><img src="images/page1_img3.jpg" alt=""></div>
						<figcaption>
							<h3>Giriş</h3>
							Websitemizde etkin içeriklere erişebilmek, daha faydalı bilgiler edinmek için kullanıcı girişi yapabilirsiniz...
							<a href="" class="btn">Detaylar</a>
						</figcaption>
					</figure>
				</div>
				<div class="clear"></div>
				</div>
				<div class="grid_12">
					 <div id="tabs">
	<ul>
		<li><a href="#tabs-1">Duyurular</a></li>
	</ul>
	<div class="clear"></div>
	
	<!-- DUYURU -->
	<?php
		$vericek=$connection->query("select * from duyuru")->fetchAll(PDO::FETCH_ASSOC);
		foreach ($vericek as $vcek)
		{
			$duyuru_id=$vcek['duyuru_id'];
			$duyuru_baslik=$vcek['duyuru_baslik'];
			$duyuru_metin=$vcek['duyuru_metin'];
	?>
	<div class="tab_cont" id="tabs-1">
		<img src="images/page1_img4.jpg" alt="">
		<div class="extra_wrapper">
			<div><u><?=$duyuru_baslik;?> </u></div>
			<p class="style1"><?=$duyuru_metin;?> </p>
<div class="clear "></div>

		</div>	
	</div>
	<?php } ?>
</div>
		</div>
	<div class="clear"></div></div>
</div>
	<div class="bottom_block">
		<div class="container_12">
			<div class="grid_2 prefix_2">
				<ul>
					<li><a href="index.php">Ana Sayfa</a></li>
					<li><a href="hakkimizda.html">Hakkımızda</a></li>
				</ul>
			</div>
			<div class="grid_2">
				<ul>
					<li><a href="galeri.html">Galeri</a></li>
					<li><a href="turmerkezleri.html">Turlarımız</a></li>
				</ul>
			</div>
			<div class="grid_2">
				<ul>
					<li><a href="giris.html">Kullanıcı Girişi</a></li>
					<li><a href="iletisim.html">İletişim</a></li>
				</ul>
			</div>
			<div class="grid_2">
				<h4>Bize Ulaşın</h4>
				TEL: 000-000-00-00<br><a href="#">info@karasu.com</a>
			 
			</div>
		<div class="clear"></div>
		</div>
	</div>
<!--==============================footer=================================-->

</div>
<footer>		
	<div class="container_12">
	<div class="grid_12">
		<div class="socials">
			<a href="#"></a>
			<a href="#"></a>
			<a href="#"></a>
			<a href="#"></a>
		</div>
			<div class="copy">
		 Mayıs &copy; 2018 | Tüm Hakları Saklıdır | Website designed by Beyzanur Demir
		 </div></div>
		 <div class="clear"></div>
	</div>

</footer>

</body>
</html>