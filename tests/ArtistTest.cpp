 /****************************************************************************************
  * Copyright (c) 2010 Leo Franchi <lfranchi@kde.org>                                    *
  *                                                                                      *
  * This program is free software; you can redistribute it and/or modify it under        *
  * the terms of the GNU General Public License as published by the Free Software        *
  * Foundation; either version 2 of the License, or (at your option) any later           *
  * version.                                                                             *
  *                                                                                      *
  * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
  * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
  * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
  *                                                                                      *
  * You should have received a copy of the GNU General Public License along with         *
  * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
  ****************************************************************************************/
 
#include "ArtistTest.h"

#include "Config.h"
#include "Artist.h"

#include <QDebug>
#include <QNetworkReply>

using namespace Echonest;

void ArtistTest::initTestCase()
{
    Config::instance()->setAPIKey( "JGJCRKWLXLBZIFAZB" );
}

void ArtistTest::testAudioUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "FooArtist" ) );
    
    QNetworkReply* reply = testArtist.fetchAudio();
    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/audio?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist" ) );
    
    reply = testArtist.fetchAudio( 15 );    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/audio?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist&results=15" ) );
    
    reply = testArtist.fetchAudio( 15, 5 );    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/audio?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist&results=15&start=5" ) );
    
    testArtist.setName( QString() );
    testArtist.setId( "ARTIST_ID" );
    reply = testArtist.fetchAudio( 15, -1 );    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/audio?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=ARTIST_ID&results=15" ) );
    
    testArtist.setName( QLatin1String( "FooArtist" ) );
    reply = testArtist.fetchAudio( 100 );    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/audio?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=ARTIST_ID&results=100" ) );
}

void ArtistTest::testBiographiesUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "FooArtist" ) );

    QNetworkReply* reply = testArtist.fetchBiographies();
    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/biographies?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist" ) );
        
    reply = testArtist.fetchBiographies( QLatin1String( "echo-source") );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/biographies?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist&license=echo-source" ) );
    
    reply = testArtist.fetchBiographies( QLatin1String( "cc-by-sa" ), 1, 5 );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/biographies?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist&results=1&start=5&license=cc-by-sa" ) );
    
}

void ArtistTest::testBlogsUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "FooArtist" ) );
    testArtist.setId( "FooId" );
    
    QNetworkReply* reply = testArtist.fetchBlogs();
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/blogs?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=FooId" ) );
    
    testArtist.setName( QLatin1String( "NoChange" ) );
    reply = testArtist.fetchBlogs( true, 10 );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/blogs?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=FooId&results=10&high_relevance=true" ) );
}

void ArtistTest::testFamiliarityUrl()
{
    Artist testArtist;
    testArtist.setId( "FooId" );
    
    QNetworkReply* reply = testArtist.fetchFamiliarity();
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/familiarity?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=FooId" ) );
}

void ArtistTest::testHotttnesssUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "FooArtist" ) );
    
    QNetworkReply* reply = testArtist.fetchHotttnesss();
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/hotttnesss?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist" ) );
}

void ArtistTest::testImagesUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "FooArtist" ) );
    
    QNetworkReply* reply = testArtist.fetchImages();
    
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/images?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist" ) );
    
    reply = testArtist.fetchImages( QLatin1String( "echo-source") );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/images?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist&license=echo-source" ) );
    
    reply = testArtist.fetchImages( QLatin1String( "cc-by-sa" ), 1, 5 );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/images?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=FooArtist&results=1&start=5&license=cc-by-sa" ) );
}

void ArtistTest::testNewsUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "FooArtist" ) );
    testArtist.setId( "FooId" );
    
    QNetworkReply* reply = testArtist.fetchNews();
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/news?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=FooId" ) );
    
    testArtist.setName( QLatin1String( "NoChange" ) );
    reply = testArtist.fetchNews( true, 10 );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/news?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=FooId&results=10&high_relevance=true" ) );
}

void ArtistTest::testProfileUrl()
{
    Artist testArtist;
    testArtist.setName( QLatin1String( "ReallyGoodArtist" ) );
    
    QNetworkReply* reply = testArtist.fetchProfile( Artist::Familiarity | Artist::Videos | Artist::Audio );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/profile?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=ReallyGoodArtist&bucket=audio&bucket=familiarity&bucket=video" ) );
    
    
    reply = testArtist.fetchProfile( Artist::Biographies | Artist::News | Artist::Reviews | Artist::Terms | Artist::Urls | Artist::MusicBrainzEntries );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/profile?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=ReallyGoodArtist&bucket=biographies&bucket=news&bucket=reviews&bucket=terms&bucket=urls&bucket=id:musicbrainz" ) );
    
    reply = testArtist.fetchProfile( Artist::Blogs | Artist::Hotttnesss | Artist::Images  | Artist::SevenDigitalEntries | Artist::PlaymeEntries );
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/profile?api_key=JGJCRKWLXLBZIFAZB&format=xml&name=ReallyGoodArtist&bucket=blogs&bucket=hotttnesss&bucket=images&bucket=id:7digital&bucket=id:playme" ) );
    
}

void ArtistTest::testReviewsUrl()
{
    Artist testArtist;
    testArtist.setId( "FooId" );
    
    QNetworkReply* reply = testArtist.fetchReviews();
    QVERIFY( reply->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/reviews?api_key=JGJCRKWLXLBZIFAZB&format=xml&id=FooId" ) );
}

void ArtistTest::testSearchUrl()
{
    Artist::SearchParams params;
    params.append( Artist::SearchParamEntry( Artist::Description, QLatin1String( "emo^2" ) ) );
    params.append( Artist::SearchParamEntry( Artist::Description, QLatin1String( "female vocalist^2" ) ) );
    params.append( Artist::SearchParamEntry( Artist::Description, QLatin1String( "-happy" ) ) );
    params.append( Artist::SearchParamEntry( Artist::FuzzyMatch, true ) );
    QNetworkReply* searchResult = Artist::search( params, Artist::Familiarity | Artist::Hotttnesss );
    
    QVERIFY( searchResult->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/search?api_key=JGJCRKWLXLBZIFAZB&format=xml&description=emo^2&description=female+vocalist^2&description=-happy&fuzzy_match=true&limit=false&bucket=familiarity&bucket=hotttnesss" ) );
    
    params.clear();
    params.append( Artist::SearchParamEntry( Artist::MaxFamiliarity, 12.221 ) );
    params.append( Artist::SearchParamEntry( Artist::MinHotttnesss, 0.52 ) );
    params.append( Artist::SearchParamEntry( Artist::Description, QLatin1String( "alternative rock" ) ) );
    params.append( Artist::SearchParamEntry( Artist::FuzzyMatch, true ) );
    searchResult = Artist::search( params, Artist::Audio | Artist::Videos, true );
    QVERIFY( searchResult->url().toString() == QLatin1String( "http://developer.echonest.com/api/v4/artist/search?api_key=JGJCRKWLXLBZIFAZB&format=xml&max_familiarity=12.221&min_hotttnesss=0.52&description=alternative+rock&fuzzy_match=true&limit=true&bucket=audio&bucket=video" ) );
    
    
}

void ArtistTest::testSimilarUrl()
{

}

void ArtistTest::testSongsUrl()
{

}

void ArtistTest::testTopHotttUrl()
{

}

void ArtistTest::testTermsUrl()
{

}

void ArtistTest::testTopTermsUrl()
{

}

void ArtistTest::testUrlsUrl()
{

}

void ArtistTest::testVideosUrl()
{

}

QTEST_MAIN(ArtistTest)

#include "ArtistTest.moc"