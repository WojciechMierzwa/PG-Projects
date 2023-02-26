<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:msxsl="urn:schemas-microsoft-com:xslt" exclude-result-prefixes="msxsl"
>
  <xsl:output method="html" indent="yes"/>

  <xsl:template match="/">

    <html>
      <head>
        <meta charset="UTF-8" />
        <title>Awatar Legenda Aanga</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <link rel="stylesheet" href="avatar1.css" />
      </head>
      <body>
        <div id="wrapper">
          
          <xsl:call-template name="nav"/>

          <div id="content">
            <h2>Grupy</h2>
              <xsl:apply-templates select="/projekt/ksiega/side/team"/>
            <xsl:apply-templates select="projekt/ranking"/>
            <xsl:apply-templates select="projekt/media/image"/>
            <xsl:apply-templates select="projekt/sezon"/>
          </div>
        </div>
        <footer>
        <xsl:apply-templates select="projekt/autor"/>
        </footer>
      </body>
    </html>

  </xsl:template>

  <xsl:template match="author">
        Wykonał
        <xsl:value-of select="name"/><xsl:text> </xsl:text>
        <xsl:value-of select="surname"/><xsl:text> </xsl:text>
        <xsl:value-of select="kierunek"/><xsl:text> </xsl:text>
        <xsl:value-of select="grupaDziekanska"/><xsl:text> </xsl:text>
        <xsl:value-of select="index"/>
  </xsl:template>

  <xsl:template name="nav">
    <nav>
      <ul>
        <li>
          <a href="Avatar HTML.html">Strona Główna</a>
        </li>
        <li>
          <a href="swiat.html">Świat</a>
        </li>
        <li>
          <a href="postacie.html">Kontakt</a>
        </li>
        <li>
          <a href="zdjecia.html">Zdjęcia</a>
        </li>
      </ul>
    </nav>
  </xsl:template>

  <xsl:template match="media/image">
    <img>
      <xsl:attribute name="src">
        <xsl:value-of select="@source"/>
      </xsl:attribute>
      <xsl:attribute name="class">
        right
      </xsl:attribute>
      <xsl:attribute name="title">
        <xsl:value-of select="."/>
      </xsl:attribute>
    </img>
  </xsl:template>

  <xsl:template match="links/link">
    <xsl:if test="not(position() = last())">
      <li>
        <a>
          <xsl:attribute name="href">
            <xsl:value-of select="@source"/>
          </xsl:attribute>
          <xsl:value-of select="."/>
        </a>
      </li>
    </xsl:if>
  </xsl:template>
  
 
  <xsl:template match="/projekt/ksiega/side/team">
    <link rel="stylesheet" href="avatar1.css" type="text/css"/>
    <html>
      <body>
        <xsl:choose>
          <xsl:when test="@leader='Awatar' ">
            <h3>
              Team Awatar <br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
            </h3>
          </xsl:when>
          <xsl:when test="@ leader='Zuko' ">
            <h3>
              Team Zuko <br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
            </h3>
          </xsl:when>
          <xsl:when test="@leader='Azula' ">
            <h3>
              Team Azula<br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
            </h3>
          </xsl:when>
          <xsl:when test="@leader='Iroh' ">
            <h3>
              White Lotus <br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
            </h3>
          </xsl:when>

        </xsl:choose>
        <table>
          <tr>
            <th>Imie</th>
            <th>Magia</th>
            <th>Broń</th>
          </tr>
          <xsl:for-each select="postac">
            <tr>
              <td>
                <xsl:value-of select="imie"/>
              </td>
              <td>
                <xsl:value-of select="magia"/>
              </td>
              <td>
                <xsl:value-of select="bron"/>
              </td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="ranking">
    <h3>
      <xsl:text>Personal Ranking of </xsl:text>
      <xsl:value-of select="count(odcinek)" />
      <xsl:text> ATLA episodes:</xsl:text>
    </h3>
    <xsl:text>&#10;</xsl:text>
    <xsl:apply-templates select="odcinek/@rank">
      <xsl:sort data-type="number" order="descending" />
    </xsl:apply-templates>
    <xsl:text>&#10;</xsl:text>
  </xsl:template>

  <xsl:template match="odcinek/@rank">
    <br></br>
    <xsl:apply-templates select=".." />
    <xsl:text> (</xsl:text>
    <xsl:value-of select="." />
    <xsl:text>)&#10;</xsl:text>
  </xsl:template>


  <xsl:template match="projekt/sezon">
    <xsl:apply-templates select="sezon/@czesc"/>
    <xsl:for-each select="rok">
      <xsl:sort select="." order="ascending"/>
      <xsl:value-of select="position()"/>
      <xsl:text>. </xsl:text>
      <xsl:value-of select="."/>
      <br/>
    </xsl:for-each>

  </xsl:template>

  <xsl:template name="Iroh" match="team">
    <xsl:if test="@leader='Iroh'">
      <xsl:text>It is time for tea</xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template name="Zuko" match="team">
    <xsl:if test="@leader='Zuko'">
      <xsl:text>My Honor</xsl:text>
    </xsl:if>
  </xsl:template>

  <xsl:template match="sezon/@czesc">
    <xsl:if test="@czesc='woda'">
      <xsl:text>Mój ulubiony sezon</xsl:text>
    </xsl:if>
  </xsl:template>

</xsl:stylesheet>
